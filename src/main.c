#include <stdlib.h>
#include <stdio.h>
#include "fibonacci/fibonacci_gui.h"
#include "bmi/bmi_gui.h"
#include "converter/base_number_gui.h"
#include "employee/employee_gui.h"

int main() {
    int option;
    int shouldRun = 1;
    while(shouldRun){
        printf_s("--------------[WELCOME]-------------\n");
        printf_s("Wybierz program:\n");
        printf_s("(1) Ciag Fibonacciego\n");
        printf_s("(2) Kalkulator BMI\n");
        printf_s("(3) Konwerter systemow liczbowych\n");
        printf_s("(4) System zarzadzania pracownikami\n");
        printf_s("(5) Zakoncz program\n");
        printf_s("------------------------------------\n");
        scanf_s("%d", &option);
        switch(option) {
            case 1: displayFibonacciGui(); break;
            case 2: displayBmiGui(); break;
            case 3: displayBaseNumberGui(); break;
            case 4: displayEmployeesGui(); break;
            case 5: shouldRun = 0; break;
            default: printf_s("Wybrales nieprawidlowy numer\n"); break;
        }
    }
    return EXIT_SUCCESS;
}