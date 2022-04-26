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
int findMax(int, int*);
int ctZero(int);
int appendMax(int, int);
int removeMax(int, int, int);

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
      printf("\nError! Positive seed values only!!\n\n");
    }

  } while(seed <= 0);

  srand(seed);
}

int getRange()
{
  int range;

  do
  {
    printf("Enter maximum power of ten for range -> ");
    scanf("%d", &range);

    if(range > 8)
    {
      printf("\nError! Power of ten cannot exceed eight!\n\n");
    }
    
    if(range <= 0)
    {
      printf("\nError! Power of ten must be positive!!\n\n");
    }
    
  } while((range > 8) || (range <= 0));

  return pow(10, range);
}

int sortInt(int number)
{
  int numberCopy;
  int sorted;
  int max;
  int maxLoc;
  int zeroCount;
  
  max = 0;
  sorted = 0;
  numberCopy = number;
  zeroCount = ctZero(numberCopy);

  while(numberCopy > 0)
  {
    max = findMax(numberCopy, &maxLoc);
    sorted = appendMax(sorted, max);
    numberCopy = removeMax(numberCopy, max, maxLoc);
  }

  sorted = sorted * (int)pow(10, zeroCount);

  return sorted;
}


int ctZero(int number)
{
  int ct = 0;

  while(number > 0)
  {
    if(number % 10 == 0)
    {
      ct++;
    }
    number = number / 10;
  }
  return ct;
}

int findMax(int number, int *maxLocation)
{
  int max;
  int location;

  max = 0;
  location = 0;

  while(number > 0)
  {
    if(number % 10 > max)
    {
      max = number % 10;
      *maxLocation = location;
    }

    number = number / 10;
    location++;
  }

  return max;
}

int appendMax(int sorted, int max)
{
  return(sorted * 10 + max);
}

int removeMax(int n, int max, int maxLoc)
{
  return(n - max * (int)pow(10, maxLoc));
}


// int sortInt(int number, int size)
// {
//   // sorts an integer by digit largest to smallest. 
//   int index;
//   int digits[size];
//   int sortedNumber;

//   //size = (int) floor(log10(number)) + 1; // length of the number
//   //digits = (int*) malloc(sizeof(int) * size); // makes an array of integers the size of the number
//   sortedNumber = 0;

//   for(index = 0; index < size; index++)
//   {
//     // make an array of dynamic size and put all the digits into that and bubble sort
//     // this way no repeat values are lost and bubble sort is easy
//     digits[index] = number % 10;
//     number /= 10;
//   }

//   bubbleSort(digits, size);

//   // sorted number is just the digit times 10^index value added together
//   for(index = size - 1; index >= 0; index--)
//   {
//     sortedNumber += digits[index] * pow(10, index);
//   }

//   return sortedNumber;
// }

void bubbleSort(int array[], int arraySize)
{
  int numPasses; // lcv that controls number of passes
  int lcv; // loop control variable for sorting
  int temp; // holds value during swap

  for(numPasses = 1; numPasses < arraySize; numPasses++)
  {
    for(lcv = 0; lcv < arraySize - numPasses; lcv++)
    {
      if(array[lcv] > array[lcv + 1])
      {
        temp = array[lcv];
        array[lcv] = array[lcv + 1];
        array[lcv + 1] = temp;
      } // end of if
    } // end of comparison loop
  } // end of passes loop

}

void fillArray(int array[], int range)
{
  int index;
  for(index = 0; index < ARRAY_SIZE; index++)
  {
    array[index] = rand() % range;
  }
}

void sortArray(int array[])
{
  int index;
  int size;
  int sortedValue;
  for(index = 0; index < ARRAY_SIZE; index++)
  {
    size = (int) floor(log10(array[index])) + 1;
    sortedValue = sortInt(array[index]);
    array[index] = sortedValue;
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