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
}

node *head = NULL;
int size = 0;

void addFirst(int data) // add first
{
	node *newNode = createNode(data);
	if (head == NULL)
	{
		head = newNode;
		size++;
		return;
	}

	newNode->next = head;
	head = newNode;
	size++;
}

void addLast(int data) // addLast
{
	node *newNode = createNode(data);
	if (head == NULL)
	{
		head = newNode;
		size++;
		return;
	}

	node *currentNode = head;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	size++;
}

void deleteFirst() // delte first
{
	if (head == NULL)
	{
		printf("This list is empty.\n");
		return;
	}
	size--;
	head = head->next;
}

void deleteLast()
{
	if (head == NULL)
	{
		printf("This list is empty.\n");
		return;
	}

	size--;
	if (head->next == NULL)
	{
		head = NULL;
		return;
	}

	node *secondLast = head;
	node *lastNode = head->next;
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
		secondLast = secondLast->next;
	}
	secondLast->next = NULL;
}

int getSize() // get size;
{
	return size;
}

void printList() // print list
{
	if (head == NULL)
	{
		printf("This list is empty.\n");
		return;
	}

	node *currentNode = head;
	while (currentNode != NULL)
	{
		printf("%d ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}

int main()
{
	addLast(10);
	addLast(20);
	addLast(30);
	addLast(40);
	deleteFirst();
	deleteLast();
	printList();
	printf("The size of the list is %d:- ", getSize());

	return 0;
}
