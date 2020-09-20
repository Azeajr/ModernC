#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(double arr[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    double L[n1], R[n2];

    int i;
    for(i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    int j;
    for(j = 0; j < n2; j++){
        R[j] = arr[middle+1 + j];
    }

    i = j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }
}

void mergesort(double arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}


void arrayRandFill(double arr[], int size){
    srand(time(NULL));

    int i;
    for(i = 0; i < size; i++){
        arr[i] = (double)rand()/((double)RAND_MAX+1);
    }
}

void printArray(double arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%f ", arr[i]);
        if(i % 5 == 4){
            printf("\n");
        }
    }
}

#define ARRAYSIZE 4

int main(int argc, char *argv[]){
    double x[ARRAYSIZE];

    arrayRandFill(x, ARRAYSIZE);
    printArray(x, ARRAYSIZE);

    printf("\n");

    mergesort(x, 0, ARRAYSIZE - 1);
    printArray(x, ARRAYSIZE);

    printf("\n");

    return 0;
}
