#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int *arr;
  int size;
  int rear;
  int front;
} queue;

void initQueue(queue *q, int n) {
  q->arr = (int *)malloc(n * sizeof(int));
  q->size = n;
  q->rear = -1;
  q->front = -1;
}

bool isEmpty(queue *q) { return q->rear == -1 && q->front == -1; }

bool isFull(queue *q) { return (q->rear + 1) % q->size == q->front; }

// enqueue
void add(queue *q, int val) {
  if (isFull(q)) {
    printf("Queue is full.\n");
    return;
  }

  if (q->front == -1) {
    q->front = 0;
  }

  q->rear = (q->rear + 1) % q->size;
  q->arr[q->rear] = val;
}

// dequeue
int removeElement(queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
    return -1;
  }

  int result = q->arr[q->front];
  if (q->rear == q->front) {
    q->rear = q->front = -1;
  } else {
    q->front = (q->front + 1) % q->size;
  }

  return result;
}

// display front element
int peek(queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
    return -1;
  }
  return q->arr[q->front];
}

int main() {
  queue q;

  initQueue(&q, 5);

  add(&q, 10);
  add(&q, 20);
  add(&q, 30);
  add(&q, 40);
  add(&q, 50);
  printf("Remove element: %d\n", removeElement(&q));
  add(&q, 60);
  printf("Remove element: %d\n", removeElement(&q));
  add(&q, 70);

  printf("\nQueue Elements:\n");
  while (!isEmpty(&q)) {
    printf("%d\n", peek(&q));
    removeElement(&q);
  }

  return 0;
}

/*
output->

Remove element: 10
Remove element: 20

Queue Elements:
30
40
50
60
70
*/