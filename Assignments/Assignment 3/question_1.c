#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int size;
  int *arr;
  int top;
} stack;

void initStack(stack *s, int n) {
  s->arr = (int *)malloc(n * sizeof(int));
  s->size = n;
  s->top = -1;
}

bool isEmpty(stack *s) { return s->top == -1; }

bool isFull(stack *s) { return s->top == s->size - 1; }

void push(stack *s, int val) {
  if (isFull(s)) {
    printf("Stack over flow.\n");
    return;
  }
  s->arr[++s->top] = val;
  printf("Push element: %d\n", val);
}

int pop(stack *s) {
  if (isEmpty(s)) {
    printf("Stack is underflow.\n");
    return -1;
  }
  int val = s->arr[s->top--];
  return val;
}

int peek(stack *s, int pos) {
  int strIdx = (s->top - pos) + 1;

  if (strIdx < 0) {
    printf("Stack is underflow.\n");
    return 0;
  }
  return s->arr[strIdx];
}

int main() {
  stack s;

  int n, ch, val;
  printf("Enter the size of the stack: ");
  scanf("%d", &n);

  initStack(&s, n);

  while (1) {
    printf("\n1.Push.\n2.Pop.\n3.Peek.\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter push element: ");
        scanf("%d", &val);
        push(&s, val);
        break;
      case 2:
        printf("Pop element: %d\n", pop(&s));
        break;
      case 3:
        for (int i = 1; i <= s.top + 1; i++) {
          printf("Position-> %d -> %d\n", s.top - i + 1, peek(&s, i));
        }
        break;
      case 4:
        printf("Exit.....\n");
        return 0;
      default:
        printf("Invalid choice !!!!.");
        break;
    }
  }
}

/*output

Enter the size of the stack: 3

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 1
Enter push element: 10
Push element: 10

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 1
Enter push element: 20
Push element: 20

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 1
Enter push element: 30
Push element: 30

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 1
Enter push element: 40
Stack over flow.

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 3
Position-> 2 -> 30
Position-> 1 -> 20
Position-> 0 -> 10

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 2
Pop element: 30

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 2
Pop element: 20

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 2
Pop element: 10

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 2
Stack is underflow.

1.Push.
2.Pop.
3.Peek.
4.Exit
Enter your choice: 4
Exit.....

*/