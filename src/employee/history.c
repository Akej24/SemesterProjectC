#include "employee.h"

static int historyEmployeesAmount = 0;

typedef struct {
    Employee* employees;
} History;

History notifyHistoryAboutEmployee(Employee employee, History history) {
    if(employee.yearbook > 2000 || employee.hoursWorked < 10) return history;
    history.employees[historyEmployeesAmount] = employee; 
    historyEmployeesAmount++;
}