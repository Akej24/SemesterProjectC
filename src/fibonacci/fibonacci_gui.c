#include <stdio.h>
#include "fibonacci.h"

void displayFibonacciGui() {
    printf_s("Wprowadz ilosc liczb ciagu Fibonacciego do wypisania: ");
    FibonacciLength range;
    
    if (scanf_s("%d", &range) != 1 || range <= 0) {
        printf_s("Niepoprawne dane, ilosc musi byc wieksza od 0 bez miejsc po przecinku\n");
        while (getchar() != '\n');
        return;
    }
    printFibonacci(range);
    printf_s("\nWygenerowano pomyslnie\n");
}