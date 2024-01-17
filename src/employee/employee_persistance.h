#include "history.h"

void saveEmployeesDataToCsv(struct Employee *employees, int employeesCurrentAmount);

struct Employee* importEmployeesDataFromCsv(const char* filename, int* amountOfEmployeesToAdd);

void generateMailsForEmployees(struct Employee *employees, int employeesCurrentAmount);