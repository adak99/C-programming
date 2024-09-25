#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue 
{
	int *arr;
	int size;
	int rear;
} queue;

void initQueue(queue *q, int n)
{
	q->arr = (int *)malloc(n *sizeof(int));
	q->size = n;
	q->rear = -1;
}

bool isEmpty(queue *q) { return q->rear == -1; }

bool isFull(queue *q) { return q->rear == q->size-1; }

//enqueue
void addElement(queue *q, int data)
{
	if(isFull(q))
	{
		printf("Queue is full.\n");
		return;
	}
	
	q->arr[++q->rear] = data;
}

//dequeue
int removeElement(queue *q)
{
	if(isEmpty(q))
	{
		printf("Queue is empty.\n");
		return -1;
	}
	
	int i, front = q->arr[0];
	
	for(i = 0; i < q->rear; i++)
	{
		q->arr[i] = q->arr[i + 1];
	}
	q->rear--;
	return front;
}

// print queue
int peek(queue *q)
{
	if(isEmpty(q))
	{
		printf("Queue is empty.\n");
		return -1;
	}
	
	return q->arr[0];
}

int main() 
{
	queue q;
	initQueue(&q, 5);

	addElement(&q, 10);
	addElement(&q, 20);
	addElement(&q, 30);
	addElement(&q, 40);
	addElement(&q, 50);
	printf("Remove element: %d\n",removeElement(&q));

	while (!isEmpty(&q)) 
	{
		printf("%d\n", peek(&q));
		removeElement(&q);
	}

	free(q.arr);
	return 0;
}

/*
	output: 
	
	Remove element: 10
	20
	30
	40
	50
*/