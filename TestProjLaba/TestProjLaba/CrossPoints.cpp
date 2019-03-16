#include "LinkedList.h"
#include "Geometry.h"
#include <stdio.h>
#include <stdlib.h>	
#include "Checks.h"
#include <math.h>
#include "Boolean.h"


Node* getIntersections(Triangle triangle, Line line)
{
	Node* head = NULL;
	//try with one malloc
	Point *crossPoint = (Point*)malloc(sizeof(Point));


	if (isOnLine(crossPoint = crossPointFinder({ { triangle.a.x, triangle.a.y },{ triangle.b.x, triangle.b.y } }, line), { { triangle.a.x, triangle.a.y },{ triangle.b.x, triangle.b.y } }))
	{
		head = add(head, crossPoint);
	}

	if (isOnLine(crossPoint = crossPointFinder({ { triangle.b.x, triangle.b.y },{ triangle.c.x, triangle.c.y } }, line), { { triangle.b.x, triangle.b.y },{ triangle.c.x, triangle.c.y } }))
	{
		head = add(head, crossPoint);
	}

	if (isOnLine(crossPoint = crossPointFinder({ { triangle.c.x, triangle.c.y },{ triangle.a.x, triangle.a.y } }, line), { { triangle.c.x, triangle.c.y },{ triangle.a.x, triangle.a.y } }))
	{
		head = add(head, crossPoint);
	}

	free(crossPoint);
	return head;
	
}


 Point * crossPointFinder(Line tringleSide, Line line)
{
	double k1 = 0, k2 = 0, b1 = 0, b2 = 0;
	
	Point * crossPoint = (Point *)malloc(sizeof(Point));
	k1 = (tringleSide.a.y - tringleSide.b.y) / (tringleSide.a.x - tringleSide.b.x);
	b1 = tringleSide.a.y - (k1*tringleSide.a.x);

	k2 = (line.a.y - line.b.y) / (line.a.x - line.b.x);
	b2 = line.a.y - (k2*line.a.x);
	
	if (tringleSide.a.x == tringleSide.b.x)
	{
		*crossPoint = { tringleSide.a.x, k2 * tringleSide.a.x + b2 };
		return crossPoint;
		//realisation
	}

	if (k1 == k2)
	{

		return NULL;
		//realisation
	}

	if (line.a.x == line.b.x)
	{
		*crossPoint = { line.a.x, k1* line.a.x + b1 };
		return crossPoint;
	}
	crossPoint->x = (b2 - b1) / (k1 - k2);
	crossPoint->y = k1 * crossPoint->x + b1;
	


	return crossPoint;
}


 Boolean isOnLine(Point* crossPoint_, Line tringleSide)
 {

	 if (crossPoint_ == NULL || crossPoint_ == nullptr) {
		 return FALSE;
	 }
	 double length1 = getLength(tringleSide);
	 
	 double length2 = getLength({ { crossPoint_->x, crossPoint_->y },{ tringleSide.a.x, tringleSide.a.y } })
		 + getLength({ { crossPoint_->x, crossPoint_->y },{ tringleSide.b.x, tringleSide.b.y } });


	
	if (round(length1*100000) == round(length2 * 100000))
		 
	 {
		 return TRUE;
	 }
	 else
	 {
		 return FALSE;
	 }
 }