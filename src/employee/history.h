#include "employee.h"

#define MAX_MESSAGE_LENGTH 80
#define MAX_HISTORY_LENGTH 100

struct History{
    struct Employee* employees;
    char* messages[MAX_HISTORY_LENGTH][MAX_MESSAGE_LENGTH];
};

void notifyHistoryAboutEmployee(struct Employee employee, struct History *history, const char* message);

void showHistory(struct History *history);