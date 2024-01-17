#include <stdio.h>
#include "employee_service.h"

void displayEmployeesGui() {
    struct Employee employees[MAX_EMPLOYEES_AMOUNT];
    struct History history;
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
        printf_s("[8] Pokaz historie\n");
        printf_s("[9] Wyjdz\n");
        printf_s("------------------------------------\n");
        if (scanf_s("%d", &option) != 1 || option <= 0) {
            printf_s("Wybrales nieprawidlowy numer\n");
            while (getchar() != '\n');
            continue;
        }
        switch(option) {
            case 1: dispatchOption(CREATE, employees, &history); break;
            case 2: dispatchOption(READ, employees, &history); break;
            case 3: dispatchOption(UPDATE, employees, &history); break;
            case 4: dispatchOption(DELETE, employees, &history); break;
            case 5: dispatchOption(IMPORT_FROM_CSV, employees, &history); break;
            case 6: dispatchOption(SAVE_TO_CSV, employees, &history); break;
            case 7: dispatchOption(GENERATE_MAILS, employees, &history); break;
            case 8: dispatchOption(SHOW_HISTORY, employees, &history); break;
            case 9: shouldRun = 0; break;
            default: printf_s("Wybrales nieprawidlowy numer\n"); break;
        }
    }
}