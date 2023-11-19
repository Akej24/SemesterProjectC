enum Gender {MALE = 'm', FEMALE = 'f'};

struct BmiInputData {
    int age;
    enum Gender gender;
    double height;
    double weight;
};

void printBmi(struct BmiInputData inputData);
void displayBmiGui();