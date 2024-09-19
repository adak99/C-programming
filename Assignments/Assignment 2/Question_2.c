#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
  int emp_no;
  char emp_name[50];
  float salary;
};

void inputEmployeeData(struct employee *emp) {
  printf("Enter Employee Number: ");
  scanf("%d", &emp->emp_no);
  getchar();

  printf("Enter Employee Name: ");
  fgets(emp->emp_name, sizeof(emp->emp_name), stdin);
  emp->emp_name[strcspn(emp->emp_name, "\n")] = '\0';

  printf("Enter Salary: ");
  scanf("%f", &emp->salary);
}

void displayEmployeeData(struct employee emp) {
  printf("\nEmployee Number: %d", emp.emp_no);
  printf("\nEmployee Name: %s", emp.emp_name);
  printf("\nSalary: %f\n", emp.salary);
}

int main() {
  int n;
  printf("Enter how many employee details you want to store: ");
  scanf("%d", &n);

  struct employee *emp = (struct employee *)malloc(n * sizeof(struct employee));

  if (emp == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  int choice, i;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Input Employee Data\n");
    printf("2. Display Employee Data\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        for (i = 0; i < n; i++) {
          printf("\nEnter details for Employee %d:\n", i + 1);
          inputEmployeeData(&emp[i]);
        }
        break;

      case 2:
        printf("\nEmployee Details:\n");
        for (i = 0; i < n; i++) {
          displayEmployeeData(emp[i]);
        }
        break;

      case 3:
        // Free the allocated memory before exiting
        free(emp);
        printf("Exiting the program.\n");
        return 0;

      default:
        printf("Invalid choice! Please enter a valid option.\n");
    }
  }

  return 0;
}

/*
output
Enter how many employee details you want to store: 1

Menu:
1. Input Employee Data
2. Display Employee Data
3. Exit
Enter your choice: 1

Enter details for Employee 1:
Enter Employee Number: 2
Enter Employee Name: Soumya
Enter Salary: 230000

Menu:
1. Input Employee Data
2. Display Employee Data
3. Exit
Enter your choice: 2

Employee Details:

Employee Number: 2
Employee Name: Soumya
Salary: 230000.000000

Menu:
1. Input Employee Data
2. Display Employee Data
3. Exit
Enter your choice: 3
Exiting the program.
*/