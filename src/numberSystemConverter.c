#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define STRINGIFY(input) #input
#define STRING_MAX_LENGTH 255

struct ConvertNumberInputData {
    char numberToConvert[STRING_MAX_LENGTH];
    int convertFrom;
    int convertOn;
};

char* buildConvertedNumberString(char result[STRING_MAX_LENGTH], int index) {
    memmove(result, result + index + 1, STRING_MAX_LENGTH - index - 1);
    result[STRING_MAX_LENGTH - index - 1] = '\0';
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

char* convertNumber(struct ConvertNumberInputData inputData) {
    int numberInDecimal = convertToDecimal(inputData.numberToConvert, inputData.convertFrom);
    return convertFromDecimal(numberInDecimal, inputData.convertOn);
}

struct ConvertNumberInputData constructConvertNumberInputData(char numberToConvert[STRING_MAX_LENGTH], int convertFrom, int convertOn) {
    struct ConvertNumberInputData inputData;
    strcpy_s(inputData.numberToConvert, numberToConvert);
    inputData.convertFrom = convertFrom;
    inputData.convertOn = convertOn;
    return inputData;
}

void printConvertedNumber(struct ConvertNumberInputData inputData) {
    char* convertedNumber = convertNumber(inputData);
    printf("\nYour converted number is: %s \n", convertedNumber);
    printf("\n(Number %s in system %d is equal to number %s in system %d)", 
        inputData.numberToConvert, 
        inputData.convertFrom, 
        convertedNumber, 
        inputData.convertOn
    );
    free(convertedNumber);
}

void displayNumberSystemConverterGui() {
    printf("\nEnter a number to convert: ");
    char numberToConvert[STRING_MAX_LENGTH];
    scanf_s("%s", &numberToConvert);

    printf("In what system is your number? [2/4/8/10/16]: ");
    int convertFrom;
    scanf_s("%d", &convertFrom);

    printf("In what system do u want to write your number? [2/4/8/10/16]: " );
    int convertOn;
    scanf_s("%d", &convertOn);

    struct ConvertNumberInputData inputData = constructConvertNumberInputData(numberToConvert, convertFrom, convertOn);
    printConvertedNumber(inputData);
}