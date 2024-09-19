#include <stdio.h>
#include <stdlib.h>

struct stack {
  int size;
  int *arr;
  int top;
};

void push(struct stack *ptr, int value) {
  if (ptr->top == ptr->size - 1) {
    printf("Stack overflow: %d can't be pushed.\n", value);
  } else {
    ptr->top++;
    ptr->arr[ptr->top] = value;
    printf("Inserted %d into the stack.\n", value);
  }
}

int pop(struct stack *ptr) {
  if (ptr->top == -1) {
    printf("Stack underflow.\n");
    return -1;
  } else {
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
  }
}

void getData(struct stack *ptr) {
  if (ptr->top == -1) {
    printf("Stack is empty.\n");
  } else {
    printf("Stack elements: \n");
    for (int i = ptr->top; i >= 0; i--) {
      printf("%d\n", ptr->arr[i]);
    }
  }
}

int main() {
  struct stack *s = (struct stack *)malloc(sizeof(struct stack));
  printf("Enter the stack size: ");
  scanf("%d", &s->size);
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));

  int choice, value;

  while (1) {
    printf("Menu:\n");
    printf("1. Push.\n");
    printf("2. Pop.\n");
    printf("3. Display.\n");
    printf("4. Exit.\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter your data: ");
        scanf("%d", &value);
        push(s, value);
        break;
      case 2:
        value = pop(s);
        if (value != -1) {
          printf("Popped value: %d\n", value);
        }
        break;
      case 3:
        getData(s);
        break;
      case 4:
        printf("Exiting program.\n");
        free(s->arr);
        free(s);
        return 0;
      default:
        printf("Enter a valid choice.\n");
        break;
    }
  }
  return 0;
}

/*output
Enter the stack size: 2
Menu:
1. Push.
2. Pop.
3. Display.
4. Exit.
Enter your choice: 1
Enter your data: 2
Inserted 2 into the stack.
Menu:
1. Push.
2. Pop.
3. Display.
4. Exit.
Enter your choice: 1
Enter your data: 3
Inserted 3 into the stack.
Menu:
1. Push.
2. Pop.
3. Display.
4. Exit.
Enter your choice: 1
Enter your data: 4
Stack overflow: 4 can't be pushed.
Menu:
1. Push.
2. Pop.
3. Display.
4. Exit.
Enter your choice: 3
Stack elements:
3
2
Menu:
1. Push.
2. Pop.
3. Display.
4. Exit.
Enter your choice: 4
Exiting program.
*/