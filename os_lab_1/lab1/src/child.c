#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/fcntl.h>

int main(int argc,char *argv[]){
    char buffer[256];
    int sum=0;
    ssize_t bytes_read; // Объявляем переменную bytes_read здесь
    while((bytes_read=read(STDIN_FILENO,buffer,sizeof(buffer)))>0){
        int num;
        char *ptr=buffer;
        char *end=ptr+bytes_read;
        while(ptr<end){
            if(*ptr>='0' && *ptr<='9'){
                num=strtol(ptr,&ptr,10);
                sum+=num;
            }else{
                ptr++;
            }
        }
    }
    char sum_str[256];
    int temp_sum = sum;
    int length = 0;

    if (temp_sum == 0) {
        sum_str[length++] = '0';
    } else if (temp_sum < 0) {
        sum_str[length++] = '-';
        temp_sum = -temp_sum;
    }

    while (temp_sum > 0) {
        int digit = temp_sum % 10;
        sum_str[length++] = digit + '0';
        temp_sum /= 10;
    }

    // Обратный порядок цифр, так как мы записывали их с конца
    for (int i = 0; i < length / 2; i++) {
        char temp = sum_str[i];
        sum_str[i] = sum_str[length - i - 1];
        sum_str[length - i - 1] = temp;
    }

    // Добавляем завершающий нуль-символ
    sum_str[length] = '\0';


    // Используем write, чтобы вывести строку
    write(STDOUT_FILENO, sum_str, length);


}
