#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

node *createNode(int new_data)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = new_data;
	newNode->next = NULL;
	return newNode;
}

node *top = NULL;
int size = 0;

void push(int data)
{
	node *newNode = createNode(data);
	if (!newNode)
	{
		printf("Stack overFlow.\n");
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

	node *temp = top;
	int popVal = top->data;
	top = top->next;
	free(temp);
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

	freeStack();
	return 0;
}