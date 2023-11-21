#include <string.h>

#define STRING_MAX_LENGTH 255

struct BaseNumber {
    char numberToConvert[STRING_MAX_LENGTH];
    int convertFrom;
    int convertOn;
};

struct BaseNumber constructBaseNumber(char numberToConvert[STRING_MAX_LENGTH], int convertFrom, int convertOn) {
    struct BaseNumber baseNumber;
    // copy given numberToConvert in place of baseNumber.numberToConvert, strcpy is needed because C does not copy array values
    strcpy(baseNumber.numberToConvert, numberToConvert);
    baseNumber.convertFrom = convertFrom;
    baseNumber.convertOn = convertOn;
    return baseNumber;
}
