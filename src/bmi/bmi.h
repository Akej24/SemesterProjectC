#include <stdbool.h>

enum Gender {MALE = 'm', FEMALE = 'f'};

struct BmiInputData {
    int age;
    enum Gender gender;
    double height;
    double weight;
};

bool areInputDataValid(struct BmiInputData inputData);

struct BmiInputData constructBmiInputData(int age, char genderShortcut, double height, double weight);