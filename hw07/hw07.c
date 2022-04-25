#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

void getSeed();
int getRange();
int sortInt(int);
void bubbleSort(int*, int);
int getValue(int*, int);
void setValue(int*, int, int);
void fillArray(int*, int);
void sortArray(int*);
void largestValues(int*);
void smallestValues(int*);

int main()
{
  int range;
  int data[ARRAY_SIZE];

  getSeed();
  range = getRange();
  fillArray(data, range);
  sortArray(data);
  largestValues(data);
  smallestValues(data);



  return 0;
}

void getSeed()
{
  int seed;

  do
  {
    printf("Enter seed value -> ");
    scanf("%d", &seed);

    if(seed <= 0)
    {
      printf("\nError! Positive seed values only!!\n");
    }
  } while(seed <= 0);

  srand(seed);
}

int getRange()
{
  int range;

  do
  {
    printf("Enter seed value -> ");
    scanf("%d", &range);

    if(range > 8)
    {
      printf("\nError! Power of ten cannot exceed eight!\n");
    }
    
    if(range <= 0)
    {
      printf("\nError! Power of ten must be positive!\n");
    }
    
  } while((range > 8) || (range <= 0));

  printf("Enter maximum power of ten for range -> ");
  scanf("%d", &range);

  return pow(10, range);
}

int sortInt(int number)
{
  // sorts an integer by digit largest to smallest. 
  int size;
  int index;
  int *digits;
  int sortedNumber;

  size = (int) floor(log10(number)) + 1; // length of the number
  digits = (int*) malloc(sizeof(int) * size); // makes an array of integers the size of the number
  sortedNumber = 0;

  for(index = 0; index < size; index++)
  {
    // make an array of dynamic size and put all the digits into that and bubble sort
    // this way no repeat values are lost and bubble sort is easy
    setValue(digits, index, number % 10);
    number /= 10;
  }

  bubbleSort(digits, size);

  // sorted number is just the digit times 10^index value added together
  for(index = size - 1; index >= 0; index--)
  {
    sortedNumber += getValue(digits, index) * pow(10, index);
  }

  return sortedNumber;
}

void bubbleSort(int *array, int arraySize)
{
  int numPasses; // lcv that controls number of passes
  int lcv; // loop control variable for sorting
  int temp; // holds value during swap

  for(numPasses = 1; numPasses < arraySize; numPasses++)
  {
    for(lcv = 0; lcv < arraySize - numPasses; lcv++)
    {
      if(getValue(array, lcv) > getValue(array, lcv + 1))
      {
        temp = getValue(array, lcv);
        setValue(array, lcv, getValue(array, lcv + 1));
        setValue(array, lcv + 1, temp);
      } // end of if
    } // end of comparison loop
  } // end of passes loop

}

void fillArray(int* array, int range)
{
  int index;
  for(index = 0; index < ARRAY_SIZE; index++)
  {
    setValue(array, index, rand() % range);
  }
}

void sortArray(int* array)
{
  int index;
  int sortedValue;
  for(index = 0; index < ARRAY_SIZE; index++)
  {
    sortedValue = sortInt(getValue(array, index));
    setValue(array, index, sortedValue);
  }

  bubbleSort(array, ARRAY_SIZE);
}

void largestValues(int *array)
{
  int index;

  printf("\nLargest 5 values in data: ");
  for(index = ARRAY_SIZE - 1; index >= ARRAY_SIZE - 5; index--)
  {
    printf("%d ", getValue(array, index));
  }
  //printf("\n");
}

void smallestValues(int *array)
{
  int index;

  printf("\nSmallest 5 values in data: ");
  for(index = 0; index < 5; index++)
  {
    printf("%d ", getValue(array, index));
  }
  printf("\n");
}

int getValue(int *array, int index)
{
  return * (array + index);
}

void setValue(int *array, int index, int value)
{
  * (array + index) = value;
}