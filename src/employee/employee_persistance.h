#include "employee.h"

void saveEmployeesDataToCsv(Employee *employees, int employeesCurrentAmount);

Employee* importEmployeesDataFromCsv(const char* filename, int* amountOfEmployeesToAdd);

void generateMailsForEmployees(Employee *employees, int employeesCurrentAmount);