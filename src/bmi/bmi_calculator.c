#include <stdio.h>
#include <math.h>
#include "bmi.h"

enum BmiCategory {UNDERWEIGHT, NORMAL, OVERWEIGHT, OBESITY};

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

void printBmi(struct BmiInputData inputData) {
    if(!areInputDataValid(inputData)) return;

    double bmi = calculateBmi(inputData);
    enum BmiCategory bmiCategory = getBmiCategory(inputData.gender, bmi);

    printf_s("\nTwoje BMI wynosi: %lf\n", bmi);
    switch(bmiCategory) {
        case UNDERWEIGHT: printf_s("Masz niedowage\n"); break;
        case NORMAL: printf_s("Twoja waga jest w normie\n"); break;
        case OVERWEIGHT: printf_s("Masz nadwage\n"); break;
        case OBESITY: printf_s("Masz otylosc\n"); break;
    }
    printf_s("\n");
}