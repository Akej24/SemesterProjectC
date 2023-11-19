#define STRING_MAX_LENGTH 200

struct ConvertNumberInputData {
    char numberToConvert[STRING_MAX_LENGTH];
    int convertFrom;
    int convertOn;
};

void printConvertedNumber(struct ConvertNumberInputData inputData);

void displayNumberSystemConverterGui();