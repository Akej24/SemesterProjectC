#include <stdio.h>
#include "bmi_calculator.h"

void displayBmiGui() {
    int age;
    printf_s("Podaj wiek: ");
    if (scanf_s("%d", &age) != 1 || age <= 0) {
        printf_s("Niepoprawne dane, wiek musi byc wiekszy od 0 bez miejsc po przecinku\n\n");
        while (getchar() != '\n');
        return;
    }

    char genderShortcut;
    printf_s("Podaj plec [M/F]: ");
    scanf_s(" %c", &genderShortcut);

    double height;
    printf_s("Podaj wzrost [m]: ");
    if (scanf_s("%lf", &height) != 1 || height <= 0) {
        printf_s("Niepoprawne dane, wzrost musi byc wiekszy od 0 bez miejsc po przecinku\n\n");
        while (getchar() != '\n');
        return;
    }

    double weight;
    printf_s("Podaj wage [kg]: ");
    if (scanf_s("%lf", &weight) != 1 || weight <= 0) {
        printf_s("Niepoprawne dane, waga musi byc wieksza od 0 bez miejsc po przecinku\n\n");
        while (getchar() != '\n');
        return;
    }

    struct BmiInputData inputData = constructBmiInputData(age, genderShortcut, height, weight);
    printBmi(inputData);
}