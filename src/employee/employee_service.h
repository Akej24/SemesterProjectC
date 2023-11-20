#include "employee.h"

enum Option {CREATE = 1, READ = 2, UPDATE = 3, DELETE = 4, IMPORT_FROM_CSV = 5, SAVE_TO_CSV = 6, GENERATE_MAILS =7};

void dispatchOption(enum Option option, struct Employee *employees);