#define MAX_EMPLOYEES_AMOUNT 10
#define MAX_NAME_LENGTH 50
#define MAX_SURNAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

enum Option {CREATE = 1, READ = 2, UPDATE = 3, DELETE = 4, GENERATE_MAILS = 5, SAVE_TO_CSV = 6};

struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char surname[MAX_SURNAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int hoursWorked;
    float brutto;
    float vat;
};

void dispatchOption(enum Option option, struct Employee *employees);

void displayEmployeesGui();