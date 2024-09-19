#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
  char arr[20];
  int top;
};

void push(struct stack *s, char ch) {
  s->top++;
  s->arr[s->top] = ch;
}

char pop(struct stack *s) {
  char ch = s->arr[s->top];
  s->top--;
  return ch;
}

void main() {
  struct stack s;
  s.top = -1;

  char str[20];
  char ch;

  printf("Enter a string: ");
  scanf("%s", str);

  for (int i = 0; i < strlen(str); i++) {
    push(&s, str[i]);
  }

  printf("Reverse String: ");
  for (int i = 0; i < strlen(str); i++) {
    ch = pop(&s);
    printf("%c", ch);
  }
}

/* output->

Enter a string: Hello
Reverse String: olleH

*/