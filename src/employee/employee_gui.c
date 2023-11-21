#include <stdio.h>
#include "employee_service.h"

void displayEmployeesGui() {
    struct Employee employees[MAX_EMPLOYEES_AMOUNT];
    int option;
    int shouldRun = 1;
    while(shouldRun){
        printf("---------------[MENU]---------------\n");
        printf_s("Wybierz opcje (wpisz numer):\n");
        printf_s("[1] Dodaj nowego pracownika\n");
        printf_s("[2] Wyswietl wszystkich pracownikow\n");
        printf_s("[3] Edytuj pracownika\n");
        printf_s("[4] Usun pracownika\n");
        printf_s("[5] Zaimportuj dane pracownikow z CSV\n");
        printf_s("[6] Zapisz dane pracownikow do CSV\n");
        printf_s("[7] Wygeneruj maile dla pracownikow\n");
        printf_s("[8] Wyjdz\n");
        printf_s("------------------------------------\n");
        if (scanf_s("%d", &option) != 1 || option <= 0) {
            printf_s("Wybrales nieprawidlowy numer\n");
            while (getchar() != '\n');
            continue;
        }
        switch(option) {
            case 1: dispatchOption(CREATE, employees); break;
            case 2: dispatchOption(READ, employees); break;
            case 3: dispatchOption(UPDATE, employees); break;
            case 4: dispatchOption(DELETE, employees); break;
            case 5: dispatchOption(IMPORT_FROM_CSV, employees); break;
            case 6: dispatchOption(SAVE_TO_CSV, employees); break;
            case 7: dispatchOption(GENERATE_MAILS, employees); break;
            case 8: shouldRun = 0; break;
            default: printf_s("Wybrales nieprawidlowy numer\n"); break;
        }
    }
}