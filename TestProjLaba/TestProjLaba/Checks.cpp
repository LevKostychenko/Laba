#include "Geometry.h"
#include <stdlib.h>
#include <stdio.h>

double numberCheck() 
{
	double checkingVar;
	while (!scanf("%lf", &checkingVar))
	{
		printf("Enter NUMBER");
		rewind(stdin);
	}
	return checkingVar;
}

int lineCheck(struct Line * line)  
{
	if ((line->a.x != line->b.x ) || (line->a.y != line->b.y))
		return 1;
	return 0;
}

int tringleCheck(struct Tringle * tringle)
{
	if (((tringle->a.x - tringle->c.x)*(tringle->b.y - tringle->c.y)) - ((tringle->b.x - tringle->c.x)*(tringle->a.y - tringle->c.y)) == 0)
		return 0;
	else
		return 1;
}