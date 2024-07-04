#include <stdio.h>
#include "funcs.h"
#include <math.h>
#include <stdbool.h>

int isprime(int n){
    if(n<=1){
        return 0;
    }
    int sqrtN=sqrt(n);
    for(int i = 2 ; i <=sqrtN;++i ){
        if(n%i==0){
            return 0;
        }
    }
    return 1;

}

int PrimeCount(int A,int B){
    int counter=0;

    for(int i = A ; i<=B;++i){
        if(isprime(i)){
            counter+=1;
        }
    }
    return counter;

}

int* sort(int* array, int size) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                swapped = true;
            }
        }
    } while (swapped);

    return array;
}
