#include <stdio.h>
#include "employee.h"

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("\n====================================\n");
        printf("       EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search for Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;

            case 2:
                displayEmployees(employees, count);
                break;

            case 3:
                searchEmployee(employees, count);
                break;

            case 4:
                calculateSalary(employees, count);
                break;

            case 5:
                printf("Exiting the system...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}