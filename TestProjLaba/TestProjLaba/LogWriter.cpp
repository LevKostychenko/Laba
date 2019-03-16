#include "Geometry.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "LogWriter.h"
#include "LinkedList.h"


void logWriter(Node* points, Triangle tringle, Line line, int countOfCrossPoints)
{
	FILE *fileptr = fopen("log.txt", "a");
	if (fileptr == NULL) {
		printf("\nError\n");
		system("pause");
	}
	timeWriter(fileptr);
	//fputs(itoa(line.a.x), fileptr);
	fprintf(fileptr, "\n Line created: {%lf; %lf}; First point {%lf; %lf}; Second point {%lf; %lf}\n", line.a.x, line.a.y, line.b.x, line.b.y);
	fprintf(fileptr, "\n Tringle created: {%lf; %lf}; First point {%lf; %lf}; Second point {%lf; %lf}; Third point {%lf;%lf}\n", tringle.a.x, tringle.a.y, tringle.b.x, tringle.b.y, tringle.c.x, tringle.c.y);
	if (countOfCrossPoints <= 0 ) {
		fprintf(fileptr, "\n Common points not found\n");
		fclose(fileptr);
		return;
	}
	
	for (Node* i = points; i!=NULL; i = i->next) {

		 {
			fprintf(fileptr, "\n Crosspoint {%lf;%lf}\n", i->point->x, i->point->y);
		}
	}
	
	fclose(fileptr);
	
}


void timeWriter(FILE *fileptr)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(fileptr, "[%d-%d-%d %d:%d:%d]\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}