#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;

    for(int j = p; j <= r-1; j++){
        if(A[j] <= x){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i + 1;
}

void quicksort(int A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}


void arrayRandFill(int arr[], int size){
    srand(time(NULL));

    int i;
    for(i = 0; i < size; i++){
        arr[i] = rand()%90 + 10;
    }
}

void printArray(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%3d ", arr[i]);
        if(i % 10 == 9){
            printf("\n");
        }
    }
}

void intArraySorted(int size, int A[]){
    for(int i = 0; i < size-1; i++){
        if(A[i] > A[i+1]){
            printf("\nArray is not sorted.\n");
            return;
        }
    }
    printf("\nArray is sorted.\n");
}

#define ARRAYSIZE 1002

int main(int argc, char const *argv[])
{
    int x[ARRAYSIZE];

    arrayRandFill(x, ARRAYSIZE);
    printArray(x, ARRAYSIZE);
    intArraySorted(ARRAYSIZE, x);

    printf("\n");

    quicksort(x, 0, ARRAYSIZE - 1);
    printArray(x, ARRAYSIZE);
    intArraySorted(ARRAYSIZE, x);

    printf("\n");

    return 0;
}