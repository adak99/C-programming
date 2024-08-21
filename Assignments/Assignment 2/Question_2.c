#include <stdio.h>
#include <string.h>

struct employee
{
    int emp_no;
    char emp_name[50];
    float salary;
};

void inputEmployeeData(struct employee *emp)
{
    printf("Enter Employee Number: ");
    scanf("%d", &emp->emp_no);
    getchar();

    printf("Enter Employee Name: ");
    fgets(emp->emp_name, sizeof(emp->emp_name), stdin);
    emp->emp_name[strcspn(emp->emp_name, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &emp->salary);
}

void displayEmployeeData(struct employee emp)
{
    printf("\nEmployee Number: %d", emp.emp_no);
    printf("\nEmployee Name: %s", emp.emp_name);
    printf("\nSalary: %f\n", emp.salary);
}

int main()
{
    struct employee emp[3];
    int choice, i;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Input Employee Data\n");
        printf("2. Display Employee Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (i = 0; i < 3; i++)
            {
                printf("\nEnter details for Employee %d:\n", i + 1);
                inputEmployeeData(&emp[i]);
            }
            break;

        case 2:
            printf("\nEmployee Details:\n");
            for (i = 0; i < 3; i++)
            {
                displayEmployeeData(emp[i]);
            }
            break;

        case 3:
            // Exit the program
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
