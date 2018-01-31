#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PartialSum{
	int p;
	int lower_bound;
	int upper_bound;
	int delta;
}PS;

FILE* file;

void readInputFile(/*...*/)
{
	int ir;
	file = fopen("input.dat", "r");
	
	while(1)
	{
		ir = fscanf(file, "%d", &ir);
		if(ir == EOF)
		{
			break;
		}
	}
}

double getPartialSum(/*...*/)
{
	
}

int main(void)
{
	
	return 0;
}
