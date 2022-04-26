/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Homework #: 7
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Creates an array of 1000 random integers, sorts
*  each integer by digit, and displays the largest and smallest 5 values in
*  the array.
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

void getSeed();
int getRange();
int sortInt(int);
void bubbleSort(int[], int);
void fillArray(int[], int);
void sortArray(int[]);
void largestValues(int[]);
void smallestValues(int[]);
int findMax(int, int*);
int ctZero(int);

int main()
{
  int range; // range of random numbers to use for data
  int data[ARRAY_SIZE]; // array of numbers to analyze

  getSeed();
  range = getRange();
  fillArray(data, range);
  sortArray(data);
  largestValues(data);
  smallestValues(data);

  return 0;
}

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A
*
*  Function Description: gets the seed from the user, makes sure it is 
*  a positive, nonzero value, and seeds the random number generator with it.
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
void getSeed()
{
  int seed; // seed to use to generate numbers

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

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: getRange
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A
*
*  Function Description: gets the range as a number from the user, 
*  the max number to generate with the random number generator
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
int getRange()
{
  int range; // max number to generate using random number generator

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

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: sortInt
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int number // unsorted integer to sort
*
*  Function Description: Given an unsorted integer, sorts the digits 
*  highest to lowest. 
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
int sortInt(int number)
{
  int sorted; // sorted number to return to the user
  int max; // current max value in the number
  int maxLoc; // location of the max value in the number
  int zeroCount; // number of zeroes in the number
  
  // initialize values
  max = 0;
  sorted = 0;
  zeroCount = ctZero(number);

  while(number > 0)
  {
    max = findMax(number, &maxLoc);
    sorted = sorted * 10 + max;
    number = number - max * (int)pow(10, maxLoc);
  }

  sorted = sorted * (int)pow(10, zeroCount);

  return sorted;
}

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: ctZero
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int number // number to count the zeroes in 
*
*  Function Description: counts and returns the number of zeroes in an 
*  inputted integer
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
int ctZero(int number)
{
  int ct; // number of zeroes

  ct = 0;

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

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: findMax
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int number // number to find the max value in
*    2. int *maxLocation // location (index) of the max value in the number
*
*  Function Description: Finds and returns the max value in an integer. Also
*  saves the index of this value to maxLocation.
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
int findMax(int number, int *maxLocation)
{
  int max; // max value
  int location; // location in the max value

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




// if only we could have used dynamic arrays...

// int sortInt(int number)
// {
//   // sorts an integer by digit largest to smallest. 
//   int index;
//   int *digits;
//   int sortedNumber;

//   size = (int) floor(log10(number)) + 1; // length of the number
//   digits = (int*) malloc(sizeof(int) * size); // makes an array of integers the size of the number
//   sortedNumber = 0;

//   for(index = 0; index < size; index++)
//   {
//     // make an array of dynamic size and put all the digits into that and bubble sort
//     // this way no repeat values are lost and bubble sort is easy
//     *(digits + index) = number % 10;
//     number /= 10;
//   }

//   bubbleSort(digits, size);

//   // sorted number is just the digit times 10^index value added together
//   for(index = size - 1; index >= 0; index--)
//   {
//     sortedNumber += *(digits + index) * pow(10, index);
//   }

//   return sortedNumber;
// }

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: bubbleSort
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[] // array to sort
*    2. int arraySize // size of the array to sort
*
*  Function Description: sorts the given array smallest to largest
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
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

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: fillArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[] // array to fill
*    2. int range // max range of values to fill the array with
*
*  Function Description: Fills the given array with numbers ranging from 
*  0 to range - 1. 
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
void fillArray(int array[], int range)
{
  int index; // index for the for loop
  for(index = 0; index < ARRAY_SIZE; index++)
  {
    array[index] = rand() % range;
  }
}

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: sortArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[]
*
*  Function Description: given an array of integers, sorts the digits of
*  each integer largest to smallest, then sorts the whole array smallest to
*  largest.
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
void sortArray(int array[])
{
  int index; // index for the for loop
  int sortedValue; // sorted current integer in the array

  for(index = 0; index < ARRAY_SIZE; index++)
  {
    sortedValue = sortInt(array[index]);
    array[index] = sortedValue;
  }

  bubbleSort(array, ARRAY_SIZE);
}

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: largestValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[] // array of sorted values
*
*  Function Description: Returns to the user the largest 5 values in the array
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
void largestValues(int array[])
{
  int index; // index for the for loop

  printf("\nLargest 5 values in data: ");
  for(index = ARRAY_SIZE - 1; index >= ARRAY_SIZE - 5; index--)
  {
    printf("%d ", array[index]);
  }
}

/*****+*-*-*---*-**---*---*--**-*----***-***--******************************
*
*  Function Information
*
*  Name of Function: smallestValues
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[] // array to display the smallest values of
*
*  Function Description: Displays to the user the smallest 5 values in the array
*
******+*-*-*---*-**---*---*--**-*----***-***--*****************************/
void smallestValues(int array[])
{
  int index; // index for the for loop

  printf("\nSmallest 5 values in data: ");
  for(index = 0; index < 5; index++)
  {
    printf("%d ", array[index]);
  }
  printf("\n");
}
