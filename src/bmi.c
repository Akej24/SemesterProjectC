#include <stdio.h>
#include <math.h>
#include <stdbool.h>

enum Gender {MALE = 'm', FEMALE = 'f'};
enum BmiCategory {UNDERWEIGHT, NORMAL, OVERWEIGHT, OBESITY};

struct BmiInputData {
    int age;
    enum Gender gender;
    double height;
    double weight;
};

enum BmiCategory getBmiCategory(enum Gender gender, double bmi) {
    switch(gender) {
    case FEMALE: 
        if (bmi < 18.5) return UNDERWEIGHT;
        else if (bmi >= 18.5 && bmi < 24.9) return NORMAL;
        else if (bmi >= 25 && bmi < 29.9) return OVERWEIGHT;
        else return OBESITY;
    case MALE:
        if (bmi < 19.5) return UNDERWEIGHT;
        else if (bmi >= 19.5 && bmi < 25.9) return NORMAL;
        else if (bmi >= 26 && bmi < 30.9) return OVERWEIGHT;
        else return OBESITY;
    }
}

double calculateBmi(struct BmiInputData inputData) {
    return inputData.weight / pow(inputData.height, 2);
}

bool areInputDataValid(struct BmiInputData inputData) {
    if(inputData.age < 0) { 
        printf("\nAge must be greater than 0");
        return false;
    }
    if(inputData.age < 18) {
        printf("\nBMI is not calculated for people under 18 years of age\n");
        return false;
    }
    if(inputData.gender != FEMALE && inputData.gender != MALE) {
        printf("\nInvalid gender, use one of these letters: F,f,M,m\n");
        return false;
    }
    if(inputData.height <= 0) {
        printf("\nHeight cannot be lesser or equal to 0.00\n");
        return false;
    }
    if(inputData.weight <= 0) {
        printf("\nWeight cannot be lesser or equal to 0.00\n");
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

void printBmi(struct BmiInputData inputData) {
    if(!areInputDataValid(inputData)) return;

    double bmi = calculateBmi(inputData);
    enum BmiCategory bmiCategory = getBmiCategory(inputData.gender, bmi);

    printf("Your bmi is: %lf\n", bmi);
    switch(bmiCategory) {
        case UNDERWEIGHT: printf("You are underweight\n"); break;
        case NORMAL: printf("You are in normal weight\n"); break;
        case OVERWEIGHT: printf("You are overweight\n"); break;
        case OBESITY: printf("You are obesity\n"); break;
    }
}

void displayBmiGui() {
    int age;
    printf("Enter your age: ");
    scanf_s("%d", &age);

    char genderShortcut;
    printf("Enter your gender [M/F]: ");
    scanf_s(" %c", &genderShortcut);

    double height;
    printf("Enter your height [m]: ");
    scanf_s("%lf", &height);

    double weight;
    printf("Enter your weight [kg]: ");
    scanf_s("%lf", &weight);

    struct BmiInputData inputData = constructBmiInputData(age, genderShortcut, height, weight);
    printBmi(inputData);
}