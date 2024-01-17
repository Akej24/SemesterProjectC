#include <stdio.h>
#include <string.h>
#include "employee.h"

#define MAX_MESSAGE_LENGTH 80
#define MAX_HISTORY_LENGTH 100

static int historyCounter = 0;

struct History {
    struct Employee employees[MAX_HISTORY_LENGTH];
    char messages[MAX_HISTORY_LENGTH][MAX_MESSAGE_LENGTH];
};

void notifyHistoryAboutEmployee(struct Employee employee, struct History *history, const char* message) {
    //add only 20+ years old employees with 10+ worked hours to history
    if (employee.yearbook >= 2000 || employee.hoursWorked <= 10) return;
    if(historyCounter < MAX_HISTORY_LENGTH) {
        history->employees[historyCounter] = employee;
        strncpy(history->messages[historyCounter], message, MAX_MESSAGE_LENGTH);
        historyCounter++;
    } 
    return;
}

void showHistory(struct History *history) {
    for (int i = 0; i < historyCounter; i++)
        printf_s("\nAkcja: '%s' dla pracownika o ID: %d", history->messages[i], history->employees[i].id);
    printf_s("\n\n");
}