#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  char name[50];
  int roll;
  int marks;
};

void studentData(struct student *ptr) {
  ptr = malloc(sizeof(struct student));

  printf("Enter the name of the student: ");
  fgets(ptr->name, sizeof(ptr->name), stdin);
  ptr->name[strcspn(ptr->name, "\n")] = '\0';

  printf("Enter the roll number of the student: ");
  scanf("%d", &(ptr->roll));

  printf("Enter the marks of the student: ");
  scanf("%d", &(ptr->marks));

  printf("\nStudent details: \n");
  printf("Name: %s\n", ptr->name);
  printf("Roll no: %d\n", ptr->roll);
  printf("Marks: %d\n", ptr->marks);
}

int main() {
  struct student *ptr;

  studentData(ptr);

  return 0;
}
