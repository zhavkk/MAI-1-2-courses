#include <stdio.h>
#include <math.h>
#include "funcs.h"
#include <stdlib.h>
#include <stdbool.h>

int PrimeCount(int A,int B){ // решето
    int N=B-A+1;
    int* massiv = (int*)malloc(N * sizeof(int));
    if (massiv == NULL) {
        printf("Memory allocation failed.\n");
        return -1;

    }   
    int counter=0;
    for(int i=2;i*i<N;++i){
        if(massiv[i]==0){
            for(int k=i*i;k<N;k+=i){
                massiv[k]=1;
            }
            
        }
    }

    for(int i=2;i<N;++i){
        if(massiv[i]==0){
            counter+=1;
        }

    }
    return counter;
}





void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, int low, int high) {
    int pivot = array[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && array[left] < pivot) {
            ++left;
        }

        while (right >= left && array[right] > pivot) {
            --right;
        }

        if (left <= right) {
            swap(&array[left], &array[right]);
        } else {
            break;
        }
    }

    swap(&array[low], &array[right]);
    return right;
}

void quicksort(int *array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

int *sort(int *array, int size) {
    quicksort(array, 0, size - 1);
    return array;
}


