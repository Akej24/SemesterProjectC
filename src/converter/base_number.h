#define STRING_MAX_LENGTH 255

struct BaseNumber {
    char numberToConvert[STRING_MAX_LENGTH];
    int convertFrom;
    int convertOn;
};

struct BaseNumber constructBaseNumber(char numberToConvert[STRING_MAX_LENGTH], int convertFrom, int convertOn);