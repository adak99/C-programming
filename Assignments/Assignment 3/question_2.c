#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

struct student {
  int roll;
  char std_name[50];
  int maths_marks;
  int english_marks;
  int total_marks;
  int rank;
};

struct stack {
  int size;
  int top;
  struct student arr[max];
};

void initStack(struct stack *s) {
  s->size = max;
  s->top = -1;
}

int isEmpty(struct stack *s) { return s->top == -1; }

int isFull(struct stack *s) { return s->top == s->size - 1; }

void push(struct stack *s, struct student value) {
  if (isFull(s)) {
    printf("Stack overflow, cannot push.\n");
  } else {
    s->top++;
    s->arr[s->top] = value;
    printf("Record pushed onto stack.\n");
  }
}

struct student pop(struct stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow.\n");
    struct student empty = {-1, "", 0, 0, 0, 0};
    return empty;
  } else {
    struct student value = s->arr[s->top];
    s->top--;
    return value;
  }
}

void getData(struct stack *s) {
  if (isEmpty(s)) {
    printf("No records to display.\n");
  } else {
    printf("Student records:\n");
    for (int i = 0; i <= s->top; i++) {
      printf(
          "Roll: %d, Name: %s, Maths: %d, English: %d, Total Marks: %d, Rank: "
          "%d\n",
          s->arr[i].roll, s->arr[i].std_name, s->arr[i].maths_marks,
          s->arr[i].english_marks, s->arr[i].total_marks, s->arr[i].rank);
    }
  }
}

void calculateTotalMarks(struct stack *s) {
  for (int i = 0; i <= s->top; i++) {
    s->arr[i].total_marks = s->arr[i].maths_marks + s->arr[i].english_marks;
  }
}

void displayRollWise(struct stack *s) {
  if (isEmpty(s)) {
    printf("No records to display.\n");
    return;
  } else {
    for (int i = 0; i <= s->top; i++) {
      for (int j = i + 1; j <= s->top; j++) {
        if (s->arr[i].roll > s->arr[j].roll) {
          struct student temp = s->arr[i];
          s->arr[i] = s->arr[j];
          s->arr[j] = temp;
        }
      }
    }
  }

  printf("Students sorted roll-wise:\n");
  getData(s);
}

void displayByMarks(struct stack *s) {
  if (isEmpty(s)) {
    printf("No records to display.\n");
    return;
  } else {
    for (int i = 0; i <= s->top; i++) {
      for (int j = i + 1; j <= s->top; j++) {
        if (s->arr[i].total_marks < s->arr[j].total_marks) {
          struct student temp = s->arr[i];
          s->arr[i] = s->arr[j];
          s->arr[j] = temp;
        }
      }
    }
  }

  printf("Students sorted by total marks (descending order):\n");
  getData(s);
}

int main() {
  struct stack s;
  initStack(&s);

  int choice;
  struct student std;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Push Student Record\n");
    printf("2. Pop Student Record\n");
    printf("3. Display All Records\n");
    printf("4. Display Students Roll Wise\n");
    printf("5. Calculate Total Marks\n");
    printf("6. Display Students by Marks\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter roll number: ");
        scanf("%d", &std.roll);
        printf("Enter name: ");
        scanf("%s", std.std_name);
        printf("Enter maths marks: ");
        scanf("%d", &std.maths_marks);
        printf("Enter english marks: ");
        scanf("%d", &std.english_marks);
        std.total_marks = std.maths_marks + std.english_marks;
        printf("Enter rank: ");
        scanf("%d", &std.rank);
        push(&s, std);
        break;
      case 2:
        std = pop(&s);
        if (std.roll != -1) {
          printf("Popped Record: Roll: %d, Name: %s\n", std.roll, std.std_name);
        }
        break;
      case 3:
        getData(&s);
        break;
      case 4:
        displayRollWise(&s);
        break;
      case 5:
        calculateTotalMarks(&s);
        printf("Total marks calculated for each student.\n");
        break;
      case 6:
        displayByMarks(&s);
        break;
      case 7:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice, please try again.\n");
        break;
    }
  }
  return 0;
}
