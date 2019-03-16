

#pragma once
#include "Point.h"

#include "Node.h"

 /*struct Node {
	Point* point;
	struct Node *next;
 };*/

Node* add( Node* node, Point* point);
void del(Node** node, Point* point);
Node* find(Node* node,Point * point);
Node* createElement(Point* point);
int countOfNodes(Node*);



