#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_EMPLOYEES 100

struct Employee {
    int employeeID;
    char name[50];
    char department[50];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double otherAllowance;
};

void addEmployee(struct Employee employees[], int *count);
void displayEmployees(struct Employee employees[], int count);
void searchEmployee(struct Employee employees[], int count);
void calculateSalary(struct Employee employees[], int count);

#endif