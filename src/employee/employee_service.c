#include <stdio.h>
#include "employee_persistance.h"

enum Option {CREATE = 1, READ = 2, UPDATE = 3, DELETE = 4, IMPORT_FROM_CSV = 5, SAVE_TO_CSV = 6, GENERATE_MAILS =7};
static int employeesCurrentAmount = 0;

int findEmployeeIndexInArrayById(int employeeId, struct Employee *employees) {
    for (int i = 0; i < sizeof(employees); ++i) 
        if (employees[i].id == employeeId) return i;
    return -1;
}

struct Employee createNewEmployee() {
    int id;
    printf_s("\nPodaj id: ");
    scanf_s("%d", &id);

    char name[MAX_STRING_LENGTH];
    printf_s("Podaj imie: ");
    scanf_s("%s", &name);

    char surname[MAX_STRING_LENGTH];
    printf_s("Podaj nazwisko: ");
    scanf_s("%s", &surname);

    char email[MAX_STRING_LENGTH];
    printf_s("Podaj email: ");
    scanf_s("%s", &email);

    int hoursWorked;
    printf_s("Podaj przepracowane godziny: ");
    scanf_s("%d", &hoursWorked);

    float brutto;
    printf_s("Podaj brutto: ");
    scanf_s("%f", &brutto);

    float vat;
    printf_s("Podaj vat: ");
    scanf_s("%f", &vat);

    printf_s("Utworzone nowego pracownika o ID: %d\n\n", id);
    return constructNewEmployee(id, name, surname, email, hoursWorked, brutto, vat);
}

void showAllEmployees(struct Employee *employees) {
    for (int i = 0; i < employeesCurrentAmount; i++) {
        printf("\n[%d]", i+1);
        printf_s("\nID pracownika: %d", employees[i].id);
        printf_s("\nImie: %s", employees[i].name);
        printf_s("\nNazwisko: %s", employees[i].surname);
        printf_s("\nEmail: %s", employees[i].email);
        printf_s("\nPrzepracowany czas: %dh", employees[i].hoursWorked);
        printf_s("\nBrutto: %.2f zl", employees[i].brutto);
        printf_s("\nVAT: %.0f%%\n", employees[i].vat);
    }
    printf("\n");
}

void editEmployee(struct Employee *employees) {
    int employeeToEditId;
    printf_s("\n\nPodaj ID pracownika do edycji: ");
    scanf_s("%d", &employeeToEditId);

    int employeeToEditIndex = findEmployeeIndexInArrayById(employeeToEditId, employees);
    printf("%d", employeeToEditIndex);

    printf_s("\nPodaj nowe dane pracownika o ID %d\n", employeeToEditId);
    printf_s("Nowe imie: ");
    scanf_s("%s", &employees[employeeToEditIndex].name);

    printf_s("Nowe nazwisko: ");
    scanf_s("%s", &employees[employeeToEditIndex].surname);

    printf_s("Nowy email: ");
    scanf_s("%s", &employees[employeeToEditIndex].email);

    printf_s("Nowe przepracowane godziny: ");
    scanf_s("%d", &employees[employeeToEditIndex].hoursWorked);

    printf_s("Nowe brutto: ");
    scanf_s("%f", &employees[employeeToEditIndex].brutto);

    printf_s("Nowy vat: ");
    scanf_s("%f", &employees[employeeToEditIndex].vat);

    printf_s("Dane pracownika o ID %d zostaly zaktualizowane.\n", employeeToEditId);
}

void deleteEmployee(struct Employee *employees) {
    int employeeToDeleteId;
    printf_s("Podaj ID pracownika do usuniecia: ");
    scanf_s("%d", &employeeToDeleteId);

    int employeeToDeleteIndex = findEmployeeIndexInArrayById(employeeToDeleteId, employees);
    for (int i = employeeToDeleteIndex; i < employeesCurrentAmount - 1; i++) 
        employees[i] = employees[i + 1];

    printf_s("\nPracownik o ID %d zostal usuniety.\n", employeeToDeleteId);
    employeesCurrentAmount--;
}


void dispatchOption(enum Option option, struct Employee *employees) {
    switch (option) {
        case CREATE: {
            struct Employee newEmployee = createNewEmployee(); 
            employees[employeesCurrentAmount] = newEmployee; 
            employeesCurrentAmount++;
            break;
        }
        case READ: showAllEmployees(employees); break;
        case UPDATE: editEmployee(employees); break;
        case DELETE: deleteEmployee(employees); break;
        case IMPORT_FROM_CSV: {
            int amountOfEmployeesToAdd = 0;
            struct Employee* importedEmployees = importEmployeesDataFromCsv("files/employees_import.csv", &amountOfEmployeesToAdd);
            for (int i = 0; i < amountOfEmployeesToAdd; ++i){
                employees[employeesCurrentAmount] = importedEmployees[i];
                employeesCurrentAmount++;
            }
            break;
        }
        case SAVE_TO_CSV: saveEmployeesDataToCsv(employees, employeesCurrentAmount); break;
        case GENERATE_MAILS: generateMailsForEmployees(employees, employeesCurrentAmount); break;
    }
}
