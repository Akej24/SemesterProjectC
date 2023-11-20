#include <string.h>

#define STRING_MAX_LENGTH 255

struct BaseNumber {
    char numberToConvert[STRING_MAX_LENGTH];
    int convertFrom;
    int convertOn;
};

struct BaseNumber constructConvertNumberInputData(char numberToConvert[STRING_MAX_LENGTH], int convertFrom, int convertOn) {
    struct BaseNumber baseNumber;
    strcpy(baseNumber.numberToConvert, numberToConvert);
    baseNumber.convertFrom = convertFrom;
    baseNumber.convertOn = convertOn;
    return baseNumber;
}
