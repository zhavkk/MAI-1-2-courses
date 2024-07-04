#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>

int main(){

    printf("0 - Change realization\n");
    printf("1 arg1 arg2 - PrimeCount function\n");
    printf("2 arg1 your array - Sort function\n");
    printf("3 - exit\n");

    int flag_lib = 1;      // номер текущей библиотеки
    void *library_handler; // прямой указатель на начало динамической библиотеки
    int *array = NULL;
    int size;

    library_handler = dlopen("librealization1.so",RTLD_LAZY);

    if (!library_handler){
        // если ошибка, то вывести ее на экран
        fprintf(stderr,"dlopen() error: %s\n", dlerror());
        exit(1); // в случае ошибки закончить работу программу
    };

    int command;
    printf("Input command: ");
    scanf("%d",&command);

    while(command != 3){
        switch (command){
        case 0:
            
            dlclose(library_handler); // закрываю текущую библиотеку

            if(flag_lib == 1){
                library_handler = dlopen("librealization2.so",RTLD_LAZY);
                flag_lib = 2;
            }
            else{
                library_handler = dlopen("librealization1.so",RTLD_LAZY);
                flag_lib = 1;
            }

            printf("\nREALIZATION CHANGED\n");

            printf("Input command: ");
            scanf("%d",&command);

            break;

        case 1:
            int x,y;

            printf("\nInput args: ");
            scanf("%d %d",&x,&y);
            printf("-----------------\n");

            int (*func_PrimeCount)(int, int); // указатель на функцию
            char name1[] = "PrimeCount";

            func_PrimeCount = dlsym(library_handler,name1);

            if (!func_PrimeCount){
                fprintf(stderr,"dlopen() error: %s\n", dlerror());
                exit(1);
            };
            
            if(flag_lib == 1) printf("\nPrimeCount realization №1\n");
            else printf("\nPrimeCount realization №2\n");

            printf("PrimeCount(%d, %d) = %d\n",x,y,(*func_PrimeCount)(x, y));
            printf("-----------------\n");

            printf("\nInput command: ");
            scanf("%d",&command);

            break;

        case 2:
            printf("Input the size of your array: ");
            scanf("%d", &size);
            array = (int *)malloc(size * sizeof(int));

            printf("Input your array: ");
            for (int i = 0; i < size; ++i) {
                scanf("%d", &array[i]);
            }

            void (*func_sort)(int *, int);
            char name2[]="sort";

            if(flag_lib == 1) printf("\nSort realization №1\n");
            else printf("\nSort realization №2\n");

            func_sort = (void (*)(int *, int))dlsym(library_handler, name2);

            if (!func_sort) {
                fprintf(stderr, "sort function error: %s\n", dlerror());
                return 1;
            }

            func_sort(array, size);

            printf("Sorted array: ");
            for (int i = 0; i < size; ++i) {
                printf("%d ", array[i]);
            }
            printf("\n");

            free(array);
            
            printf("\nInput command: ");
            scanf("%d",&command);

            break;
        case 3:
            break;
        default:

            printf("\nIncorrect Input\n");
        
            exit(1);
        
            break;
        }
    }
    dlclose(library_handler);
}