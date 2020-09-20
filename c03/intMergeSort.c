/*
 * A merge sort (with recursion) on arrays with sort keys such as double or
 * strings to your liking? Nothing is gained if you don’t know whether your
 * programs are correct. Therefore, can you provide a simple test routine that
 * checks if the resulting array really is sorted? This test routine should just
 * scan once through the array and should be much, much faster than your sorting
 * algorithms.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    int i;
    for(i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    int j;
    for(j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    #if 1
    i = 0;
    j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    #endif



    /*
     * I thought this was supposed to work
     */
    #if 0
    /*int k;
    for(i = 0, j = 0, k = left; k < right; k++){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }*/
    #endif
}

void mergesort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
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

#define ARRAYSIZE 4

int main(int argc, char *argv[]){
    int x[ARRAYSIZE];

    arrayRandFill(x, ARRAYSIZE);
    printArray(x, ARRAYSIZE);

    printf("\n");

    mergesort(x, 0, ARRAYSIZE - 1);
    printArray(x, ARRAYSIZE);

    printf("\n");

    return 0;
}
