#include <stdio.h>
#include <stdlib.h>
#include "ValidCrossPoint.h"


Boolean valid(Line triangleSide, Line line)
{
	Boolean boolean;
	//Point* point =(Point*)malloc(sizeof(Point));
	Point* point = crossPointFinder(triangleSide, line);
	
	if (point == nullptr || point == NULL) return FALSE;

	boolean = isOnLine(point, triangleSide);
	return boolean;
}

