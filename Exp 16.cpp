#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void writeEmployee(FILE *file, struct Employee emp, int index) {
    fseek(file, index * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);
}

struct Employee readEmployee(FILE *file, int index) {
    struct Employee emp;
    fseek(file, index * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);
    return emp;
}

int main() {
    FILE *file;
    struct Employee emp;

    file = fopen("employees.dat", "wb+");
    if (!file) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Writing employee details
    emp.id = 1;
    strcpy(emp.name, "John Doe");
    emp.salary = 50000.0;
    writeEmployee(file, emp, 0);

    emp.id = 2;
    strcpy(emp.name, "Jane Smith");
    emp.salary = 60000.0;
    writeEmployee(file, emp, 1);

    // Reading employee details
    struct Employee emp1 = readEmployee(file, 0);
    printf("Employee ID: %d, Name: %s, Salary: %.2f\n", emp1.id, emp1.name, emp1.salary);

    struct Employee emp2 = readEmployee(file, 1);
    printf("Employee ID: %d, Name: %s, Salary: %.2f\n", emp2.id, emp2.name, emp2.salary);

    fclose(file);
    return 0;
}
