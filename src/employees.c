#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES_AMOUNT 10
#define MAX_STRING_LENGTH 80
#define MAX_FILE_NAME 1000
#define MAX_TEMPLATE_LENGTH 1000

enum Option {CREATE = 1, READ = 2, UPDATE = 3, DELETE = 4, GENERATE_MAILS = 5, SAVE_TO_CSV = 6};
static int employeesIndexCounter = -1;

struct Employee {
    int id;
    char name[MAX_STRING_LENGTH];
    char surname[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    int hoursWorked;
    float brutto;
    float vat;
};

void saveEmployeesDataToCsv(struct Employee *employees) {
    char fileName[MAX_FILE_NAME];
    sprintf(fileName, "employees.csv");
    FILE *file = fopen(fileName, "w");
    if (file != NULL) {
        fprintf(file, "\"id\";\"name\";\"surname\";\"email\";\"hoursWorked\";\"brutto\";\"vat\"\n");
        for (int i = 0; i <= employeesIndexCounter; i++) {
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

char* calculateSalary(float brutto, float vatInPercent, int hoursWorked) {
    float totalSalary = brutto * hoursWorked;
    float totalSalaryMinusVat = totalSalary * (1 - vatInPercent/100);
    char resultString[MAX_STRING_LENGTH];
    sprintf(resultString, "%.2f", totalSalaryMinusVat);
    return strdup(resultString);
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

void generateMailsForEmployees(struct Employee *employees) {
    for (int i = 0; i <= employeesIndexCounter; i++) {
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

int findEmployeeIndexInArrayById(int employeeId, struct Employee *employees) {
    for (int i = 0; i < sizeof(employees); ++i) 
        if (employees[i].id == employeeId) return i;
    return -1;
}

struct Employee constructNewEmployee(int id, char name[MAX_STRING_LENGTH], char surname[MAX_STRING_LENGTH], char email[MAX_STRING_LENGTH], int hoursWorked, float brutto, float vat) {
    struct Employee newEmployee;
    newEmployee.id = id;
    strcpy(newEmployee.name, name);
    strcpy(newEmployee.surname, surname);
    strcpy(newEmployee.email, email);
    newEmployee.hoursWorked = hoursWorked,
    newEmployee.brutto = brutto;
    newEmployee.vat = vat;
    return newEmployee;
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
    employeesIndexCounter++;
    return constructNewEmployee(id, name, surname, email, hoursWorked, brutto, vat);
}

void showAllEmployees(struct Employee *employees) {
    for (int i = 0; i <= employeesIndexCounter; i++) {
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
    printf_s("Podaj numer pracownika do usuniecia: ");
    scanf_s("%d", &employeeToDeleteId);

    int employeeToDeleteIndex = findEmployeeIndexInArrayById(employeeToDeleteId, employees);
    for (int i = employeeToDeleteIndex; i < employeesIndexCounter - 1; i++) 
        employees[i] = employees[i + 1];

    printf_s("\nPracownik o ID %d zostal usuniety.\n", employeeToDeleteId);
    employeesIndexCounter--;
}

void dispatchOption(enum Option option, struct Employee *employees) {
    switch (option) {
        case CREATE: {
            struct Employee newEmployee = createNewEmployee(); 
            employees[employeesIndexCounter] = newEmployee; 
            break;
        }
        case READ: showAllEmployees(employees); break;
        case UPDATE: editEmployee(employees); break;
        case DELETE: deleteEmployee(employees); break;
        case GENERATE_MAILS: generateMailsForEmployees(employees); break;
        case SAVE_TO_CSV: saveEmployeesDataToCsv(employees); break;
    }
}

void displayEmployeesGui() {
    struct Employee employees[MAX_EMPLOYEES_AMOUNT];
    int option;
    while(1){
        printf("---------------[MENU]---------------\n");
        printf_s("Wybierz opcje (wpisz numer):\n");
        printf_s("[1] Dodaj nowego pracownika\n");
        printf_s("[2] Wyswietl wszystkich pracownikow\n");
        printf_s("[3] Edytuj pracownika\n");
        printf_s("[4] Usun pracownika\n");
        printf_s("[5] Wygeneruj maile dla pracownikow\n");
        printf_s("[6] Zapisz dane pracownikow do CSV\n");
        printf("------------------------------------\n");
        scanf_s("%d", &option);
        switch(option) {
            case 1: dispatchOption(CREATE, employees); break;
            case 2: dispatchOption(READ, employees); break;
            case 3: dispatchOption(UPDATE, employees); break;
            case 4: dispatchOption(DELETE, employees); break;
            case 5: dispatchOption(GENERATE_MAILS, employees); break;
            case 6: dispatchOption(SAVE_TO_CSV, employees); break;
            default: printf_s("Wybrales nieprawidlowy numer\n"); break;
        }
    }
}