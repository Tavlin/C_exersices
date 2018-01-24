#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// struct says: "DON'T ASSSUME MY SIZE"

// capacity == max number of elements that fit in the allocated storage
// size == #elements stored in the vector
long int capacity, size;
double* vector;

void createVector(const unsigned int numberOfElements, /*const*/ double* value)
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
	
	vector = (double*)malloc(capacity * sizeof(double));
	
	// (c) set the size of our vector to numberOfElements and initialize the first 
	// elements of vector to value.
	
	size = numberOfElements;
	vector = value;
	
}

void destroyVector(void)
{
	free(vector);
	size = capacity = 0;
	vector = NULL;
}

// retrieve content with boundary check
double at(const unsigned int index)
{
	if(index >= size)
	{
		printf("index is bigger then vector size");
		exit(0);
	}
	
	return vector[index];
}

// to add an element at the end
void pushBack(const double value)
{	
	
	size += 1;
	
	if(capacity <= size)
	{
		capacity *= 2;
		printf("size = %ld\t capacity = %ld\n", size, capacity);
	
	double* new_vector;
	new_vector = (double *)realloc(vector, capacity*sizeof(double));
		if(new_vector == NULL)
		{
			printf("error: realloc gone wrong!\n");
			exit(0);
		}
		vector = new_vector;
	}
	//free(new_vector);	

	//vector[size-1] = value;
	
}

//to remove an element at the end
void popBack(void)
{	
	
	//vector[size-1] = NULL; // NULL type is void, values of pointer are double :c
	//free(&vector[size-1]);
	size -= 1;
	
	while((capacity/2) > size)
	{
		capacity /= 2;
	}
	
	if((vector = (double *)realloc((void *)vector,
	(capacity)*sizeof(double))) == NULL)
	{
		printf("error: realloc gone wrong!\n");
		exit(0);
	}
	vector = (double *)realloc((void *)vector,(capacity)*sizeof(double));
}

// print function
void print_vector(double * vector)
{
	for(int i = 0; i < size; i++)
	{
		printf("vector[%d] = %lf\n", i, vector[i]);
	}
}

int main(int argc, char *argv[])
{
	double start_vector[argc];
	for(int i = 0; i < argc ; i++)
	{
		start_vector[i] = atoi(argv[i]);
	}
	printf("peep\n");
	createVector(12, start_vector);
	print_vector(vector);
	
	const unsigned int asdf = 3;
	printf("using at %d: %lf\n", asdf, at(asdf));
	
	/*
	pushBack(14);
	pushBack(14);
	pushBack(14);
	pushBack(14);
	pushBack(14);
	pushBack(14);
	pushBack(14);
	pushBack(14);
	pushBack(14);
	pushBack(14);
	pushBack(14);
	print_vector(vector);*/
	popBack();
	print_vector(vector);
	
	return 0;
}
