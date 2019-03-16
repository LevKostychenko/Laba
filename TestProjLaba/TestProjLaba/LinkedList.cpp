#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node* createElement(Point* point)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->point = point;
	node->next = NULL;
	return node;
}

Node* add(Node* node, Point* point)
{
	if (node == NULL)
	{
		node = createElement(point);
	}
	else if (node->next == NULL)
	{
		node->next = createElement(point);
	}
	else
	{
		Node* next = node->next;
		node->next = createElement(point);
		node->next->next = next;
	}
	return node;
}


void del(Node** head, Point * point)
{
	if (!head) return;
	if ((*head)->point == point)
	{
		Node* current = *head;
		*head = (*head)->next;
		free(current);
	}
	Node* previous = find(*head, point);
}

Node* find(Node* head, Point* point)
{
	for (Node* i = head; i != NULL; i = i->next)
	{
		if (i->point == point) return i;
	}
	return NULL;
}

int countOfNodes(Node* head)
{
	int countOfNodes = 0;
	for (Node* i = head; i != NULL; i = i->next)
		countOfNodes++;
	return countOfNodes;
}

