#include "FileChouse.h"
#include <stdio.h>
#include<stdlib.h>
#include "FileRead.h"
void fileChouse()
{
	int numberOfFile;
	printf("\nChose line (1/2/3)\n");
	while (scanf("%d", &numberOfFile))
	{
		if (numberOfFile < 1 || numberOfFile > 3)
			printf("\nIncorrect value entered");

		else break;
		rewind(stdin);
	}
	switch (numberOfFile)
	{
	case 1: fileRead("line1.txt");
		break;
	case 2: fileRead("line2.txt");
		break;
	case 3: fileRead("line3.txt");
		break;
	
	
	}
}