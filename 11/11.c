#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// capacity == max number of elements that fit in the allocated storage
// size == #elements stored in the vector
long int capacity, size;
double* vector;

void createVector(const unsigned int numberOfElements, const double* value)
{
	// (a) set capacity to the smallest power of 2 larger than the provided 
	// numberOfElements
	
	long int x = 2;
	while(x < numberOfElements)
	{
		x *= 2;  
	}
	
	capacity = x;
	
	// (b) make a first memory allocation of capacity*sizeof(/*type*/) bytes,
	// using the malloc function;
	
	vector = (double*)malloc(capacity*sizeof(double));
	
	// (c) set the size of our vector to numberOfElements and initialize the first 
	// elements of vector to value.
	
	size = numberOfElements;
	vector = value;
	
}

void destroyVector(void)
{
	free(vector);
}

// retrieve content with boundary check
double at(const unsigned int index)
{
	if(index > size)
	{
		printf("index is bigger then vector size");
		exit(0);
	}
	
	return vector[index];
}

// to add an element at the end
void pushBack(const double value)
{
	if(capacity <= size)
	{
		capacity *= 2;
		if((vector = (double *)realloc((void *)vector,
		(capacity)*sizeof(double))) == NULL)
		{
			printf("Fehler: realloc fehlgeschlagen!\n");
			exit(0);
		}
	}
	
}

//to remove an element at the end
void popBack(void)
{
	
}

int main(void)
{
	
	return 0;
}
