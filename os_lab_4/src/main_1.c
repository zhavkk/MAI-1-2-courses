#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(){
    
    printf("1 arg1 arg2 - PrimeCount function\n");
    printf("2 arg1 your array - Sort function\n");
    printf("3 - exit\n");

    int command;
    int *array = NULL;

    printf("Input command: ");
    scanf("%d",&command);

    while(command != 3){
        switch (command){
        case 1:

            int x,y;

            printf("\nInput args: ");
            scanf("%d %d",&x,&y);
            printf("-----------------\n");

            printf("PrimeCount(%d, %d) = %d\n",x,y,PrimeCount(x,y));
            printf("-----------------\n");

            printf("\nInput command: ");
            scanf("%d",&command);

            break;
        case 2:

            int size;
            printf("Input the size of your array: ");
            scanf("%d", &size);
            array = (int *)malloc(size * sizeof(int));

            printf("Input your array: ");
            for (int i = 0; i < size; ++i) {
                scanf("%d", &array[i]);
            }

            int *sortedArray = sort(array, size);

            printf("Sorted array: ");
            for (int i = 0; i < size; ++i) {
                printf("%d ", sortedArray[i]);
            }
            printf("\n");
            free(sortedArray);
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
}