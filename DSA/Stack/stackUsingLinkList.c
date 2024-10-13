#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

node *top = NULL;
int size = 0;

void push(int data)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if (top == NULL)
	{
		top = newNode;
		return;
	}

	newNode->next = top;
	top = newNode;
}

int pop()
{
	if (top == NULL)
	{
		printf("Stack is empty.");
		return -1;
	}

	int popVal = top->data;
	top = top->next;
	return popVal;
}

int peek()
{
	if (top == NULL)
	{
		printf("Stack is empty.");
		return -1;
	}

	return top->data;
}

void display()
{
	if (top == NULL)
	{
		printf("Stack is empty.");
		return;
	}

	node *currentNode = top;
	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}
}

int main()
{
	push(10);
	push(20);
	push(30);
	pop();
	display();

	while (top != NULL)
	{
		printf("Peek: %d\n", peek());
		pop();
	}

	return 0;
}
