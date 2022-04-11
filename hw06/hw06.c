#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 75

void input();
void fillData(int*);
double mean(int*);
double standardDeviation(int*);
int getValue(int*, int);
void setValue(int*, int, int);
void outputs(double, double, int*);



int main()
{
  int data[ARRAY_SIZE];
  double meanValue;
  double stdev;

  input();
  fillData(data);
  meanValue = mean(data);
  stdev = standardDeviation(data);
  outputs(meanValue, stdev, data);

  return 0;
}

void input()
{
  int seed;

  printf("Enter seed value -> ");
  scanf("%d", &seed);
  srand(seed);
}
void fillData(int* data)
{
  int x;
  int randomValue;

  for(x = 0; x < ARRAY_SIZE; x++)
  {
    randomValue = (rand() % 100) + 1;
    setValue(data, x, randomValue);
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

double standardDeviation(int* array)
{
  double stdev;
  double variance;
  double meanValue;
  int x;
  double sumDifferenceSquares;

  sumDifferenceSquares = 0;
  meanValue = mean(array);

  for(x = 0; x < ARRAY_SIZE; x++)
  {
    sumDifferenceSquares += pow((getValue(array, x) - meanValue), 2);
  }

  variance = sumDifferenceSquares / (ARRAY_SIZE - 1);
  stdev = sqrt(variance);

  return stdev;
}

int getValue(int *array, int index)
{
  return * (array + index); // aka array[index] but with pointers
}

void setValue(int *array, int index, int value)
{
  * (array + index) = value; // aka array[index] = value; but with pointers
}

void outputs(double mean, double stdev, int* data)
{
  int x; // index variable for the for loop
  int currentValue;
  printf("\n");
  printf("Data set mean: %.1f\n", mean);
  printf("Data set standard deviation: %.1f\n", stdev);

  printf("Values less than one deviation from mean: ");
  for(x = 0; x < ARRAY_SIZE; x++)
  {
    currentValue = getValue(data, x);
    if(currentValue - mean < (-1 * stdev))
    {
      printf("%d ", currentValue);
    }
  }
  printf("\n");

  printf("Values greater than one deviation from mean: ");
  for(x = 0; x < ARRAY_SIZE; x++)
  {
    currentValue = getValue(data, x);
    if(currentValue - mean > stdev)
    {
      printf("%d ", currentValue);
    }
  }
  printf("\n");
}