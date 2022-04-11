#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 75

void fillData(int, int*);
void setValue(int*, int, int);
int getValue(int*, int);
double mean(int*);


int main()
{
  int data[ARRAY_SIZE];
  fillData(1000, data);

  printf("%.1f", mean(data));

  return 0;
}

void fillData(int seed, int* data)
{
  int x;
  int randomValue;

  srand(seed);

  for(x = 0; x < ARRAY_SIZE; x++)
  {
    randomValue = (rand() % 100) + 1;
    setValue(data, x, randomValue);
    printf("%d\n", randomValue);
  }

}

double mean(int* array)
{
  double meanValue;
  double sum;
  int x;

  sum = 0;
  for(x = 0; x < ARRAY_SIZE; x++)
  {
    sum += getValue(array, x);
  }

  meanValue = sum / ARRAY_SIZE;
  return meanValue;
}

int getValue(int *array, int index)
{
  return * (array + index); // aka array[index] but with pointers
}

void setValue(int *array, int index, int value)
{
  * (array + index) = value; // aka array[index] = value; but with pointers
}