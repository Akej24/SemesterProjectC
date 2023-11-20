#include <stdio.h>
#include <stdbool.h>

enum Gender {MALE = 'm', FEMALE = 'f'};

struct BmiInputData {
    int age;
    enum Gender gender;
    double height;
    double weight;
};

bool areInputDataValid(struct BmiInputData inputData) {
    if(inputData.age < 0) { 
        printf_s("\nWiek musi byc liczba naturalna dodatnia\n\n");
        return false;
    }
    if(inputData.age < 18) {
        printf_s("\nBMI nie jest liczone dla osob ponizej 18 roku zycia\n\n");
        return false;
    }
    if(inputData.gender != FEMALE && inputData.gender != MALE) {
        printf_s("\nWybierz jedna plec sposrod podanych: F,f,M,m\n\n");
        return false;
    }
    if(inputData.height <= 0) {
        printf_s("\nWzrost nie moze byc liczba ujemna\n\n");
        return false;
    }
    if(inputData.weight <= 0) {
        printf_s("\nWaga nie moze byc liczba ujemna\n\n");
        return false;
    }
    return true;
}

struct BmiInputData constructBmiInputData(int age, char genderShortcut, double height, double weight) {
    enum Gender gender;
    if(genderShortcut == 'F' || genderShortcut == 'f') gender = FEMALE;
    else if(genderShortcut == 'M' || genderShortcut == 'm') gender = MALE;

    struct BmiInputData bmiInputData;
    bmiInputData.age = age;
    bmiInputData.gender = gender;
    bmiInputData.height = height;
    bmiInputData.weight = weight;
    return bmiInputData;
}