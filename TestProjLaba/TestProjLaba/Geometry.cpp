#include "Geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include "Checks.h"
#include <math.h>

double getLength( Line line)
{
	return fabs(sqrt(pow((line.a.x - line.b.x), 2)
		+ pow((line.a.y - line.b.y), 2)));
}


Point getPointCoordinates(double x, double y)
{
	return { x, y };
}

Line getLineCoordinates(double arrayOfCoordinates[4])
{
	Line line = {getPointCoordinates(arrayOfCoordinates[0], arrayOfCoordinates[1]), 
		getPointCoordinates(arrayOfCoordinates[2], arrayOfCoordinates[3])};
	return line;
}

Triangle getTringleCoordinates(double arrayOfCoordinates[6])
{
	Triangle triangle = { getPointCoordinates(arrayOfCoordinates[0], arrayOfCoordinates[1]),
		getPointCoordinates(arrayOfCoordinates[2], arrayOfCoordinates[3]),
		getPointCoordinates(arrayOfCoordinates[4], arrayOfCoordinates[5]) };
	return triangle;
}
