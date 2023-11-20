#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long BigDecimal;
typedef int FibonacciLength;

BigDecimal* assignFibonacciSequenceMemory(FibonacciLength range) { 
    BigDecimal* fibonacciSequence = malloc(range * sizeof(BigDecimal));
    if (fibonacciSequence == NULL) {
        printf_s("Niepoprawnie zaalokowana pamiec dla dlugosci ciagu Fibonacciego\n");
        exit(EXIT_FAILURE);
    }
    return fibonacciSequence;
}

BigDecimal* generateFibonacci(FibonacciLength range) {
    BigDecimal* fibonacciSequence = assignFibonacciSequenceMemory(range);
    fibonacciSequence[0] = 0;
    fibonacciSequence[1] = 1;

    for(int i=2; i<range; i++) 
        fibonacciSequence[i] = fibonacciSequence[i-1] + fibonacciSequence[i-2];

    return fibonacciSequence;
}

bool checkIfSequenceNumberIsAboveLimit(int i, BigDecimal previous, BigDecimal current) {
    if(i > 0 && current < previous) {
        printf_s("%d. liczba jest poza maskymalnym zakresem", i);
        return true;
    }
    return false;
}

void printFibonacci(FibonacciLength range) {
    BigDecimal* fibonacciSequence = generateFibonacci(range);
    for(int i=0; i<range; i++) {
        if(checkIfSequenceNumberIsAboveLimit(i, fibonacciSequence[i-1], fibonacciSequence[i])) break;
        printf_s("%d. liczba ciagu Fibonacciego: %llu\n", i, fibonacciSequence[i]);
    }

    free(fibonacciSequence);
}