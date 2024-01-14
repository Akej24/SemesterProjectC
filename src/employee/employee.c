#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 80
#define MAX_EMPLOYEES_AMOUNT 10

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    char surname[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    int hoursWorked;
    float brutto;
    float vat;
    int yearbook;
} Employee;


Employee constructNewEmployee(int id, char name[MAX_STRING_LENGTH], char surname[MAX_STRING_LENGTH], char email[MAX_STRING_LENGTH], int hoursWorked, float brutto, float vat, int yearbook) {
    Employee newEmployee;
    newEmployee.id = id;
    strcpy(newEmployee.name, name);
    strcpy(newEmployee.surname, surname);
    strcpy(newEmployee.email, email);
    newEmployee.hoursWorked = hoursWorked,
    newEmployee.brutto = brutto;
    newEmployee.vat = vat;
    newEmployee.yearbook = yearbook;
    return newEmployee;
}

char* calculateSalary(float brutto, float vatInPercent, int hoursWorked) {
    float totalSalary = brutto * hoursWorked;
    float totalSalaryMinusVat = totalSalary * (1 - vatInPercent/100);
    char resultString[MAX_STRING_LENGTH];
    sprintf(resultString, "%.2f", totalSalaryMinusVat);
    return strdup(resultString);
}