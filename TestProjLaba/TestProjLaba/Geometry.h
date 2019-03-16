#pragma once
#include "Checks.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "LinkedList.h"
#include "Boolean.h"
double getLength(struct Line);
struct Point getPointCoordinates(double, double);
struct Line getLineCoordinates(double[4]);
struct Triangle getTringleCoordinates(double[6]);
struct Node* getIntersections(struct Triangle, struct Line);
struct Point * crossPointFinder(struct Line, struct Line);
Boolean isOnLine(struct Point*, struct Line );
