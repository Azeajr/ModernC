#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(double A[], int p, int r){
    double x = A[r];
    int i = p-1;

    for(int j = p; j <= r-1; j++){
        if(A[j] <= x){
            i++;
            double temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    double temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i + 1;
}

void quicksort(double A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}


double randDouble(double min, double max){
    return (double)rand() * (max-min)/((double)RAND_MAX + 1) + min;
}

void fillArrayRandDouble(int size, double arr[], double start, double end){
    srand(time(NULL));

    int i;
    for(i = 0; i < size; i++){
        *(arr+i) = randDouble(start, end);
    }
}

void printArrayDouble(int size, double arr[]){
    int i;
    for(i = 0;  i < size; i++){
        printf("%4lf ", *(arr+i));
        if(i % 10 == 9) printf("\n");
    }
}

void doubleArraySorted(int size, double A[]){
    for(int i = 0; i < size-1; i++){
        if(A[i] > A[i+1]){
            printf("\nArray is not sorted.\n");
            return;
        }
    }
    printf("\nArray is sorted.\n");
}

#define ARRAYSIZE 100

int main(int argc, char const *argv[])
{
    double x[ARRAYSIZE];

    fillArrayRandDouble(ARRAYSIZE, x, 0.0, 1.0);

    printArrayDouble(ARRAYSIZE, x);
    doubleArraySorted(ARRAYSIZE, x);
    printf("\n");

    quicksort(x, 0, ARRAYSIZE - 1);
    printArrayDouble(ARRAYSIZE, x);
    doubleArraySorted(ARRAYSIZE, x);
    printf("\n");

    return 0;
}