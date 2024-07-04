#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <stdbool.h>


int main(int argc , char *argv[]){

    fflush(stdout);
    int fd[2];
    
    if(pipe(fd)==-1){
        write(STDERR_FILENO,"Pipe wasnt created",19);
    }
    int fd2[2];
    if(pipe(fd2)==-1){
        write(STDERR_FILENO,"Pipe wasnt created",19);
    }

    pid_t pid = fork();

    if(pid==-1){
        write(STDERR_FILENO,"fork",5);
        exit(-1);
    }

    if(pid==0){// работа в дочернем процессе
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);

        close(fd2[0]);
        dup2(fd2[1],STDOUT_FILENO);
        execvp("./child", argv);
    }
    if(pid>0){
        usleep(100000);
        char filename[256]= "kostyl"; 
        read(STDIN_FILENO,filename,256);
        int pos=strlen(filename)-1;
        if(filename[pos]=='\n'){
            filename[pos]='\0';
        }

        //открываем файл
        printf("#%s#\n", filename);
        int file = open(filename,O_RDONLY);
        char numbers[256];
        int flag=1;
        if(file!=-1){
            read(file,numbers,256);
            write(STDERR_FILENO,"file uspeshno otkrit\n",22);
        }
        else{
            write(STDERR_FILENO,"uspeha otkrit file netu\n",22);
            flag=0;
        }
        //закрываем дискриптор чтения, передаем данные из файла в буффер nubmers дочернему процесус
        close(fd[0]);
        write(fd[1],numbers,256);
        close(fd[1]);

        //получаем конечные данные от child 

        close(fd2[1]);
        char ans[256]=" ";
        read(fd2[0],ans,256);
        if(ans[0]==' '){
            exit(1);
        }
        if(flag){
            write(STDOUT_FILENO,ans,256);
            write(STDOUT_FILENO,"\n",2);

        }
        else{
            exit(1);
        }


        close(fd2[0]);
    }
    return 0;
}