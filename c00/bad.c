#include <stdio.h>
/*
 * The third difference is that getting-started.c
 * inluded stdlib.h to use EXIT_SUCCESS
 * This program was missing the inclusion of stdio.h
 * because printf is defined there. The main function
 * should have returned int instead of void
 */

int main(int argc, char *argv[]){
    int i;
    double A[5] = {
        9.0,
        2.9,
        3.E+25,
        .00007,
    };

    for(i = 0; i < 5; ++i){
        printf("element %d is %g, \tits square is %g\n",
                i,
                A[i],
                A[i] * A[i]);
    }

    return 0;
}
