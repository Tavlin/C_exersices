#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TYPE double

/*
YDFU = You done fucked up
*/
struct Vector{
	unsigned int capacity;
	unsigned int size;
	TYPE* vector;
};



struct Vector createVector(const unsigned int numberOfElements, const TYPE value)
{
	struct Vector v;
	
	if(numberOfElements == 0)
	{
		v.capacity = 2;
	}
	else
	{
		v.capacity = (unsigned int)pow(2, ceil(log(numberOfElements)/log(2)));
		//ceil returns the smallest integral value not less than numberOfElements
	}

  v.vector = (TYPE *)malloc(v.capacity*sizeof(TYPE));
  if(v.vector == NULL){
    printf("ERROR: malloc failed! Aborting...\n");
    exit(42);
  }
  v.size = numberOfElements;
  for(unsigned int i=0; i<numberOfElements; i++)
    v.vector[i] = value;
    
  return v;
}

void destroyVector(struct Vector* toBeDestroyed)
{
	 free(toBeDestroyed -> vector);
   toBeDestroyed -> size =  toBeDestroyed -> capacity = 0;     
}

TYPE at(struct Vector myVector, const unsigned int index)
{
	if(index >= myVector.size)
	{
  	printf("YDFU: \"at\" function called with too big index!\n");
    exit(42);
  }
  
  else
  {
  	return myVector.vector[index];
  }
}

void pushBack(struct Vector* myVector, const TYPE value)
{
	if(myVector -> capacity == myVector -> size)
	{
		myVector -> capacity *= 2;
		TYPE* newVector = (TYPE*)realloc(myVector -> vector,
		myVector -> capacity*sizeof(TYPE));
    if(newVector == NULL)
    {
    	printf("YDFU: realloc failed\n");
    	free(myVector -> vector);
    	exit(42);
    }
    else
    {
    	myVector -> vector = newVector;
    }
	}
	myVector -> vector[(myVector -> size)++] = value;
}

void popBack(struct Vector * myVector)
{
	if(myVector -> size > 0)
	{	
		myVector -> vector[--myVector -> size] = 0;
	}
}

unsigned int sizeOf(const struct Vector myVector)
{
	return myVector.size;
}

unsigned int capacityOf(const struct Vector myVector)
{
	return myVector.capacity;
}

TYPE * getRawPointer(const struct Vector myVector)
{
	return myVector.vector;
}

int main(void)
{
	struct Vector hector = createVector(1,1);
	struct Vector* phector = &hector;
	
	int i = 1;
	
	do
	{
		pushBack(phector, at(hector, i-1) + pow((i+1),-2));
		printf("capacity = %d\n", capacityOf(hector));
		i++;
		
	} while((phector -> vector[phector -> size-1] - 
	phector -> vector[phector -> size-2]) > 0.000001);
	return 0;
}
