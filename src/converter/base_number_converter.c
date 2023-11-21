#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "base_number.h"

char* buildConvertedNumberString(char result[STRING_MAX_LENGTH], int index) {
    printf("liczba %s\n", result);
    printf("result %s index %d\n", result, index);
    // converted number is written like xxx1010101 in an array, so we want to 
    // move it in variable 'result', 
    // on index 'result + index + 1', 
    // copy 'string max length - index - 1' chars (~how many times do it)
    // xxx1110101 -> 1110101xxx
    memmove(result, result + index + 1, STRING_MAX_LENGTH - index - 1);
    result[STRING_MAX_LENGTH - index - 1] = '\0';
    printf("liczba %s", result);
    return result;
}

char writeDigitAsChar(int digit) {
    switch (digit) {
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        default: return digit + '0';
    }
}

char* convertFromDecimal(int decimalNumber, int convertTo) {
    char* result = malloc(STRING_MAX_LENGTH * sizeof(char));
    if (result == NULL) {
        printf_s("Niepoprawnie zaalokowana pamiec dla zmiennej result przy konwersji z liczby dziesietnej\n");
        exit(EXIT_FAILURE);
    }
    int index = STRING_MAX_LENGTH - 1;
    while (decimalNumber != 0) {
        int rest = decimalNumber % convertTo;
        result[index] = writeDigitAsChar(rest);
        --index;
        decimalNumber /= convertTo;
    }
    return buildConvertedNumberString(result, index);
}

int writeCharAsDigit(char letter) {
    switch (letter) {
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        default: return letter - '0';
    }
}

int convertToDecimal(char numberToConvert[STRING_MAX_LENGTH], int convertFrom) {
    int amountOfDigits = strlen(numberToConvert);
    int index = amountOfDigits - 1;
    int result = 0;
    while (index >= 0) {
        char currentChar = numberToConvert[index];
        int digit = writeCharAsDigit(currentChar);
        result += digit * pow(convertFrom, (amountOfDigits - 1) - index);
        index--;
    }
    return result;
}

char* convertNumber(struct BaseNumber baseNumber) {
    int numberInDecimal = convertToDecimal(baseNumber.numberToConvert, baseNumber.convertFrom);
    return convertFromDecimal(numberInDecimal, baseNumber.convertOn);
}

void printConvertedNumber(struct BaseNumber baseNumber) {
    char* convertedNumber = convertNumber(baseNumber);
    printf_s("\nTwoja liczba po konwersji to: %s \n", convertedNumber);
    printf_s("\n(Liczba %s w systemie %d jest rowna liczbie %s w systemie %d)\n", 
        baseNumber.numberToConvert, 
        baseNumber.convertFrom, 
        convertedNumber, 
        baseNumber.convertOn
    );
    free(convertedNumber);
}