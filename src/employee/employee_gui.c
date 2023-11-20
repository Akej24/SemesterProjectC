#include <stdio.h>
#include "employee_crud_service.h"

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
        printf_s("[7] Zaimportuj dane pracownikow z CSV\n");
        printf("------------------------------------\n");
        scanf_s("%d", &option);
        switch(option) {
            case 1: dispatchOption(CREATE, employees); break;
            case 2: dispatchOption(READ, employees); break;
            case 3: dispatchOption(UPDATE, employees); break;
            case 4: dispatchOption(DELETE, employees); break;
            case 5: dispatchOption(GENERATE_MAILS, employees); break;
            case 6: dispatchOption(SAVE_TO_CSV, employees); break;
            case 7: dispatchOption(IMPORT_FROM_CSV, employees); break;
            default: printf_s("Wybrales nieprawidlowy numer\n"); break;
        }
    }
}