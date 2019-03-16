#include <stdio.h>
#include "Geometry.h"
#include "CrosspointsDisplay.h"

void crossPointsDisplay(Node* head)
{
	if (head == NULL)
	{
		printf("No points of intersection\n");
		return;
	}
	for (Node* i = head; i != NULL; i = i->next)
	{
		printf("%lf; %lf \n", i->point->x, i->point->y);
	}

}