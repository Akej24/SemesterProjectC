#include "employee.h"

enum Option {CREATE = 1, READ = 2, UPDATE = 3, DELETE = 4, GENERATE_MAILS = 5, SAVE_TO_CSV = 6, IMPORT_FROM_CSV = 7};

void dispatchOption(enum Option option, struct Employee *employees);