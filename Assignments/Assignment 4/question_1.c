#include <stdio.h>
#include <stdlib.h>

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

node *front = NULL;
node *rear = NULL;

int isEmpty() { return rear == -1; }

void enqueue(int data)
{
	node *newNode = createNode(data);
	if (rear == NULL)
	{
		front = rear = newNode;
		return;
	}

	rear->next = newNode;
	rear = newNode;
}

int dequeue()
{
	if (isEmpty())
	{
		printf("Queue is empty.\n");
		return -1;
	}

	int frontVal = front->data;
	front = front->next;
	return frontVal;
}

int peek()
{
	if (isEmpty())
	{
		printf("Queue is empty.\n");
		return -1;
	}

	return front->data;
}

void display()
{
	if (isEmpty())
	{
		printf("Queue is empty.\n");
		return;
	}

	node *currentNode = front;
	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}
}

int main()
{

	enqueue(10);
	enqueue(20);
	enqueue(30);

	printf("Display->\n");
	display();
	printf("Peek\n");

	while (rear != NULL)
	{
		printf("%d\n", peek());
		dequeue();
	}

	return 0;
}