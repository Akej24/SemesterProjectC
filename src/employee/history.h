#include "employee.h"

typedef struct {
    Employee* employees;
} History;

History notifyHistoryAboutEmployee(Employee employee);