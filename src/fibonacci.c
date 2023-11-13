#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

unsigned long long* generateFibonacci(unsigned int range) {
    unsigned long long * fibonacciSequence = (unsigned long long*) malloc((unsigned long long)range * sizeof(unsigned long long));
    if (fibonacciSequence == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    fibonacciSequence[0] = 0;
    fibonacciSequence[1] = 1;

    for(int i=2; i<range; i++) 
        fibonacciSequence[i] = fibonacciSequence[i-1] + fibonacciSequence[i-2];

    return fibonacciSequence;
}

void printFibonacci(unsigned int range) {
    if (range < 2) {
        printf("Range must be greater than or equal to 2\n");
        return;
    }

    unsigned long long* sequenceToPrint = generateFibonacci(range);

    for(int i=0; i<range; i++) {
        if(i > 0 && sequenceToPrint[i] < sequenceToPrint[i-1]) {
            printf("Out of unsigned long long value");
            break;
        }
        printf("%d. number of Fibonacci sequence %llu\n", i, sequenceToPrint[i]);
    }

    free(sequenceToPrint);
}

void displayFibonacciGui() {
    unsigned int range;
    printf("Enter a range of Fibonacci sequence (greater than 0): ", range);
    scanf("%u", &range);
    printFibonacci(range);
}