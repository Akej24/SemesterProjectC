#include <stdio.h>
#include "base_number_converter.h"

void displayBaseNumberGui() {
    printf_s("\nWprowadz liczbe do przekonwertowania: ");
    char numberToConvert[STRING_MAX_LENGTH];
    scanf_s("%s", &numberToConvert);

    printf("W jakim systemie jest twoja liczba? [2/4/8/10/16]: ");
    int convertFrom;
    if (scanf_s("%d", &convertFrom) != 1 || convertFrom <= 0) {
        printf_s("Niepoprawne dane, liczba musi byc wieksza od 0 bez miejsc po przecinku\n\n");
        while (getchar() != '\n');
        return;
    }

    printf("Na jaki system chcesz ja przekonwertowac? [2/4/8/10/16]: " );
    int convertOn;
    if (scanf_s("%d", &convertOn) != 1 || convertOn <= 0) {
        printf_s("Niepoprawne dane, system musi byc wiekszy od 0 bez miejsc po przecinku\n\n");
        while (getchar() != '\n');
        return;
    }

    struct BaseNumber baseNumber = constructBaseNumber(numberToConvert, convertFrom, convertOn);
    printConvertedNumber(baseNumber);
}