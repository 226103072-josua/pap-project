#include <stdio.h>
#include <string.h>
#include "employee.h"

void addEmployee(struct Employee employees[], int *count) {
    int id;
    int i;

    if (*count >= MAX_EMPLOYEES) {
        printf("Employee limit reached!\n");
        return;
    }

    printf("\n========== ADD EMPLOYEE ==========\n");
    printf("Enter Employee ID: ");
    scanf("%d", &id);

   
    for (i = 0; i < *count; i++) {
        if (employees[i].employeeID == id) {
            printf("Employee ID already exists!\n");
            return;
        }
    }

    employees[*count].employeeID = id;
    getchar();

    printf("Enter Employee Name: ");
    fgets(employees[*count].name, 50, stdin);
    employees[*count].name[
        strcspn(employees[*count].name, "\n")
    ] = '\0';

    printf("Enter Department: ");
    fgets(employees[*count].department, 50, stdin);
    employees[*count].department[
        strcspn(employees[*count].department, "\n")
    ] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%lf", &employees[*count].basicSalary);

    printf("Enter Housing Allowance: ");
    scanf("%lf", &employees[*count].housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%lf", &employees[*count].transportAllowance);

    printf("Enter Other Allowance: ");
    scanf("%lf", &employees[*count].otherAllowance);

    (*count)++;

    printf("Employee added successfully!\n");
}

void displayEmployees(struct Employee employees[], int count) {
    int i;

    if (count == 0) {
        printf("No employees available.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (i = 0; i < count; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %d\n", employees[i].employeeID);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: %.2f\n",
               employees[i].housingAllowance);
        printf("Transport Allowance: %.2f\n",
               employees[i].transportAllowance);
        printf("Other Allowance: %.2f\n",
               employees[i].otherAllowance);
    }
}

void searchEmployee(struct Employee employees[], int count) {
    int id, i, found = 0;

    if (count == 0) {
        printf("No employees available to search.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (employees[i].employeeID == id) {
            printf("\nEmployee Found!\n");
            printf("Employee ID: %d\n", employees[i].employeeID);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: %.2f\n",
                   employees[i].housingAllowance);
            printf("Transport Allowance: %.2f\n",
                   employees[i].transportAllowance);
            printf("Other Allowance: %.2f\n",
                   employees[i].otherAllowance);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d was not found.\n", id);
    }
}

void calculateSalary(struct Employee employees[], int count) {
    int id, i, found = 0;
    double grossSalary, tax, netSalary;

    if (count == 0) {
        printf("No employees available.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (employees[i].employeeID == id) {
            grossSalary = employees[i].basicSalary
                        + employees[i].housingAllowance
                        + employees[i].transportAllowance
                        + employees[i].otherAllowance;

            if (grossSalary <= 5000) {
                tax = grossSalary * 0.10;
            } else if (grossSalary <= 10000) {
                tax = grossSalary * 0.15;
            } else {
                tax = grossSalary * 0.20;
            }

            netSalary = grossSalary - tax;

            printf("\n========== SALARY INFORMATION ==========\n");
            printf("Employee ID: %d\n", employees[i].employeeID);
            printf("Employee Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Gross Salary: %.2f\n", grossSalary);
            printf("Tax: %.2f\n", tax);
            printf("Net Salary: %.2f\n", netSalary);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d was not found.\n", id);
    }

}

