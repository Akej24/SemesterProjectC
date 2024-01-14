#define MAX_STRING_LENGTH 80
#define MAX_EMPLOYEES_AMOUNT 10

typedef struct  {
    int id;
    char name[MAX_STRING_LENGTH];
    char surname[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    int hoursWorked;
    float brutto;
    float vat;
    int rocznik;
} Employee;

typedef struct  { 



Employee** employee;

} History;



struct Employee constructNewEmployee(int id, char name[MAX_STRING_LENGTH], char surname[MAX_STRING_LENGTH], char email[MAX_STRING_LENGTH], int hoursWorked, float brutto, float vat);

char* calculateSalary(float brutto, float vatInPercent, int hoursWorked);