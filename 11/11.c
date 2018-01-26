#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct says: "DON'T ASSSUME MY SIZE"
// capacity == max number of elements that fit in the allocated storage
// size == #elements stored in the vector
long int capacity, size;
double* vector;

void createVector(const unsigned int numberOfElements, /*const*/ double* value) {
	long int x = 2;
	while(x < numberOfElements) {
		x *= 2;  
	} 
	capacity = x; 
	vector = (double*)malloc(capacity * sizeof(double)); 
	size = numberOfElements;
  for(int i=0;i<numberOfElements;i++) {
    vector[i] = value[i]; 
  }
}

void destroyVector(void) {
	free(vector); size = capacity = 0; vector = NULL;
}

double at(const unsigned int index) {
	if(index >= size) {
		printf("index is bigger then vector size\n");
		exit(0);
	} 
	return vector[index];
}

void pushBack(const double value) {	
  size += 1; 
  if(capacity <= size) {
    capacity *= 2;
    printf("inside push back size = %ld\t capacity = %ld\n", size, capacity); 
    double* new_vector = (double *)realloc(vector, capacity*sizeof(double));
    printf("you'll never see me!\n");
  }
}

void popBack(void) {	
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

void print_vector(double * vector) {
  printf("size = %ld \t capacity = %ld\n",size,capacity);
	for(int i = 0; i < size; i++) {
		printf("vector[%d] = %lf\n", i, vector[i]);
	}
}

int main(int argc, char *argv[])
{
	double start_vector[argc];
//	for(int i = 0; i < argc ; i++) {
//		start_vector[i] = atoi(argv[i]);
    
  for(int i = 0; i < 3 ; i++) {
    start_vector[i] = 3-i;
}
	createVector(3, start_vector);
	print_vector(vector);
	
//	const unsigned int asdf = 3;
//	printf("using at %d: %lf\n", asdf, at(asdf));
	
	pushBack(14);
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
	print_vector(vector);*/
//	popBack();
//	print_vector(vector);
	
	return 0;
}
