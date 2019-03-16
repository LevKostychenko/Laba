#include "FileRead.h"
#include <stdio.h>
#include <stdlib.h>
#include "Geometry.h"
#include "LogWriter.h"
#include "CrosspointsDisplay.h"

void fileRead(char fileName[20])
{
	FILE *TrianglePoints;
	FILE *LinePoints;
	int _countOfNodes = 0, count = 0;

	double _arrayForLineCoordinates[4];
	double _arrayForTriangleCoordinates[6];
	Line line;
	Triangle triangle;
	//выбранный файл с линией 
	LinePoints = fopen(fileName, "r");
	TrianglePoints = fopen("triangle.txt", "r");
	
	while (fscanf(TrianglePoints, "%lf", &_arrayForTriangleCoordinates[count]) != EOF)
	{
			count++;
	}
	triangle = getTringleCoordinates(_arrayForTriangleCoordinates);

	fclose(TrianglePoints);
	count = 0;
	while (fscanf(LinePoints, "%lf", &_arrayForLineCoordinates[count]) != EOF )
	{
 		 count++;
	}
	line = getLineCoordinates(_arrayForLineCoordinates);

	fclose(LinePoints);

	Node* head = getIntersections(triangle, line);
	_countOfNodes = countOfNodes(head);
	crossPointsDisplay(head);
	logWriter(head, triangle, line, _countOfNodes);

	




}






