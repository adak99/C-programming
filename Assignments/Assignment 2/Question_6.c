#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  int roll;
  char name[50];
  char address[100];
  int age;
  float avg;
};

void display(struct student stud) {
  printf("\nRoll: %d\n", stud.roll);
  printf("Name: %s\n", stud.name);
  printf("Address: %s\n", stud.address);
  printf("Age: %d\n", stud.age);
  printf("Average Marks: %.2f\n", stud.avg);
}

int main() {
  int n;
  printf("Enter the number student how many student data you want to store: ");
  scanf("%d", &n);

  struct student *students =
      (struct student *)malloc(n * sizeof(struct student));

  int i;

  for (i = 0; i < n; i++) {
    printf("\nEnter details for student %d:\n", i + 1);

    printf("Roll No: ");
    scanf("%d", &students[i].roll);
    getchar();

    printf("Name: ");
    fgets(students[i].name, sizeof(students[i].name), stdin);
    students[i].name[strcspn(students[i].name, "\n")] = '\0';

    printf("Address: ");
    fgets(students[i].address, sizeof(students[i].address), stdin);
    students[i].address[strcspn(students[i].address, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &students[i].age);

    printf("Average Marks: ");
    scanf("%f", &students[i].avg);
  }

  printf("\nDisplaying details of all students:\n");
  for (i = 0; i < n; i++) {
    display(students[i]);
  }

  return 0;
}

/*
Output->

Enter the number student how many student data you want to store: 2

Enter details for student 1:
Roll No: 101
Name: John Doe
Address: 123 Maple Street
Age: 20
Average Marks: 85.5

Enter details for student 2:
Roll No: 102
Name: Jane Smith
Address: 456 Oak Avenue
Age: 22
Average Marks: 90.25

Displaying details of all students:

Roll: 101
Name: John Doe
Address: 123 Maple Street
Age: 20
Average Marks: 85.50

Roll: 102
Name: Jane Smith
Address: 456 Oak Avenue
Age: 22
Average Marks: 90.25

*/