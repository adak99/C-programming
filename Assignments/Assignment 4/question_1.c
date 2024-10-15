#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

node *createNode(int newData)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = newData;
	newNode->next = NULL;
	return newNode;
}

typedef struct Queue
{
	node *front;
	node *rear;
	int size;
} queue;

void initQueue(queue *q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

bool isEmpty(queue *q) { return q->rear == NULL; }

void enqueue(queue *q, int data)
{
	node *newNode = createNode(data);
	if (q->rear == NULL)
	{
		q->front = q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}
	q->size++;
}

int dequeue(queue *q)
{
	if (isEmpty(q))
	{
		printf("Queue is empty.\n");
		return -1;
	}

	node *temp = q->front;
	int remove_val = temp->data;
	q->front = q->front->next;

	if (q->front == NULL)
	{
		q->rear = NULL;
	}

	free(temp);
	q->size--;
	return remove_val;
}

int peek(queue *q) // Return front value of the queue
{
	if (isEmpty(q))
	{
		printf("Queue is empty.\n");
		return -1;
	}

	return q->front->data;
}

void display(queue *q)
{
	if (isEmpty(q))
	{
		printf("Queue is empty.\n");
		return;
	}

	node *currentNode = q->front;
	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}
}

int getSize(queue *q)
{
	return q->size;
}

int main()
{
	queue q;
	initQueue(&q);

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);

	printf("Peek-> %d\n", peek(&q));
	printf("Dequeue-> %d\n", dequeue(&q));
	printf("Display-> \n");
	display(&q);
	printf("Get size-> %d\n", getSize(&q));

	return 0;
}
