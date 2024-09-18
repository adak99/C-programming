#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int *arr;
  int size;
  int rear;
} queue;

void initQueue(queue *q, int n) {
  q->arr = (int *)malloc(n * sizeof(int));
  q->size = n;
  q->rear = -1;
}

bool isEmpty(queue *q) { return q->rear == -1; }

// enqueue
void add(queue *q, int data) {
  if (q->rear == q->size - 1) {
    printf("Queue is full.\n");
    return;
  }
  q->arr[++q->rear] = data;
}

// dequeue
int removeElement(queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
    return -1;
  }

  int front = q->arr[0];
  for (int i = 0; i < q->rear; i++) {
    q->arr[i] = q->arr[i + 1];
  }
  q->rear--;
  return front;
}

// peek
int peek(queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
    return -1;
  }

  return q->arr[0];
}

int main() {
  queue q;
  int n;
  printf("Enter how many elements you want to store in a queue: ");
  scanf("%d", &n);

  initQueue(&q, n);

  int choice, data;

  while (1) {
    printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter your data: ");
        scanf("%d", &data);
        add(&q, data);
        break;
      case 2:
        printf("Removed element: %d\n", removeElement(&q));
        break;
      case 3:
        while (!isEmpty(&q)) {
          printf("%d\n", peek(&q));
          removeElement(&q);
        }
        break;
      case 4:
        printf("Exiting...\n");
        free(q.arr);
        return 0;
      default:
        printf("Invalid choice! Please try again.\n");
        break;
    }
  }

  return 0;
}
