#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

#define MAX_FILE_NAME 1000
#define MAX_TEMPLATE_LENGTH 1000

void replaceGap(char* textWithGaps, char* gap, char* valueToFill){
    char *occurrence = strstr(textWithGaps, gap);
    size_t gapLength = strlen(gap);
    size_t valueToFillLength = strlen(valueToFill);
    while (occurrence != NULL) {
        memmove(occurrence + valueToFillLength, occurrence + gapLength, strlen(occurrence + gapLength) + 1);
        strncpy(occurrence, valueToFill, valueToFillLength);
        occurrence = strstr(occurrence + valueToFillLength, gap);
    }
    free(occurrence);
}

char* replaceGaps(char* textWithGaps, struct Employee employee) {    
    char stringVat[MAX_STRING_LENGTH];
    sprintf(stringVat, "%.1f", employee.vat);

    char hoursWorkedString[MAX_STRING_LENGTH];
    sprintf(hoursWorkedString, "%d", employee.hoursWorked);
    char* salary = calculateSalary(employee.brutto, employee.vat, employee.hoursWorked);

    replaceGap(textWithGaps, "$EMAIL", employee.email);
    replaceGap(textWithGaps, "$NAME", employee.name);
    replaceGap(textWithGaps, "$SURNAME", employee.surname);
    replaceGap(textWithGaps, "$SALARY", salary);
    replaceGap(textWithGaps, "$HOURS_WORKED", hoursWorkedString);
    replaceGap(textWithGaps, "$VAT", stringVat);
    return textWithGaps;
}

char* readTemplate(char* templateFileName) {
    FILE *file = fopen(templateFileName, "r");
    if (file == NULL) {
        printf("Blad podczas otwierania pliku %s", templateFileName);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(length + 1);
    if (buffer == NULL) {
        printf("Nie udało się zaalokować pamięci dla pliku %s", templateFileName);
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    fclose(file);
    buffer[length] = '\0';
    return buffer;
}

void saveEmployeesDataToCsv(struct Employee *employees, int employeesCurrentAmount) {
    char fileName[MAX_FILE_NAME];
    sprintf(fileName, "employees.csv");
    FILE *file = fopen(fileName, "w");
    if (file != NULL) {
        fprintf(file, "\"id\";\"name\";\"surname\";\"email\";\"hoursWorked\";\"brutto\";\"vat\"\n");
        for (int i = 0; i < employeesCurrentAmount; i++) {
            fprintf(file, "\"%d\";", employees[i].id);
            fprintf(file, "\"%s\";", employees[i].name);
            fprintf(file, "\"%s\";", employees[i].surname);
            fprintf(file, "\"%s\";", employees[i].email);
            fprintf(file, "\"%d\";", employees[i].hoursWorked);
            fprintf(file, "\"%.2f\";", employees[i].brutto);
            fprintf(file, "\"%.2f\"", employees[i].vat);
            fprintf(file, "\n");
        }
        fclose(file);
    } else printf("Nie mozna otworzyc pliku employees.csv\n");
}

struct Employee* importEmployeesDataFromCsv(const char* filename, int* amountOfEmployeesToAdd) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    struct Employee* employees = malloc(MAX_EMPLOYEES_AMOUNT * sizeof(struct Employee));
    if (employees == NULL) {
        perror("Error allocating memory for employees");
        fclose(file);
        return NULL;
    }
    char line[2560];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "\"id\";\"name\";\"surname\";\"email\";\"hoursWorked\";\"brutto\";\"vat\"") != NULL) continue;

        struct Employee newEmployee;
        sscanf(line, "\"%d\";\"%49[^\"]\";\"%49[^\"]\";\"%49[^\"]\";\"%d\";\"%f\";\"%f\"",
               &newEmployee.id, newEmployee.name, newEmployee.surname, newEmployee.email,
               &newEmployee.hoursWorked, &newEmployee.brutto, &newEmployee.vat);

        employees[*amountOfEmployeesToAdd] = newEmployee;
        (*amountOfEmployeesToAdd)++;
        if (*amountOfEmployeesToAdd >= MAX_EMPLOYEES_AMOUNT) break;
    }
    fclose(file);
    struct Employee* resizedEmployees = realloc(employees, (*amountOfEmployeesToAdd) * sizeof(struct Employee));
    if (resizedEmployees == NULL) {
        perror("Error resizing memory for employees");
        free(employees);
        return NULL;
    }
    return resizedEmployees;
}

void generateMailsForEmployees(struct Employee *employees, int employeesCurrentAmount) {
    for (int i = 0; i < employeesCurrentAmount; i++) {
        char emailFileName[MAX_FILE_NAME];
        sprintf(emailFileName, "employee_email_%d.txt", employees[i].id);
        FILE *emailFile = fopen(emailFileName, "w");
        if (emailFile != NULL) {
            char* textWithGaps = readTemplate("template.txt");
            char* textToSave = replaceGaps(textWithGaps, employees[i]);
            fwrite(textToSave, 1, strlen(textToSave), emailFile);
            fclose(emailFile);
        } else printf("Blad podczas otwierania pliku emial dla pracownika o id: %d\n", employees[i].id);
    }
}