/*****+******--***------*-*--**---*-****-***--******************************
*
*  Homework #: 6
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:
*
******+******--***------*-*--**---*-****-***--*****************************/

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
  int data[ARRAY_SIZE]; // array to hold the random numbers
  double meanValue; // mean of the data set
  double stdev; // standard deviation of the data set

  input();

  fillData(data);
  meanValue = mean(data);
  stdev = standardDeviation(data);

  outputs(meanValue, stdev, data);

  return 0;
}

/*****+*-****--***------*-*--**---*-****-***--******************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description: Gets and sets the seed value for the random 
*  number generator function
*
******+*-****--***------*-*--**---*-****-***--*****************************/
void input()
{
  int seed; // seed value to use

  printf("Enter seed value -> ");
  scanf("%d", &seed);
  srand(seed);
}

/*****+*-****--***------*-*--**---*-****-***--******************************
*
*  Function Information
*
*  Name of Function: fillData
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *data // pointer to the array of data
*
*  Function Description: fills the data array with random numbers between 
*  1 and 100, inclusive.
*
******+*-****--***------*-*--**---*-****-***--*****************************/
void fillData(int *data)
{
  int x; // index used in for loop
  int randomValue; // random value to assign to the index in data

  for(x = 0; x < ARRAY_SIZE; x++)
  {
    randomValue = (rand() % 100) + 1;
    setValue(data, x, randomValue);
  }

}

/*****+*-****--***------*-*--**---*-****-***--******************************
*
*  Function Information
*
*  Name of Function: mean
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *array // pointer to the array of data to find the mean of
*
*  Function Description: finds the mean of the data set given by the 
*  inputted array
*
******+*-****--***------*-*--**---*-****-***--*****************************/
double mean(int *array)
{
  double meanValue; // mean value of the array
  double sum; // sum of all elements in array
  int x; // used in the for loop as an index

  sum = 0;
  for(x = 0; x < ARRAY_SIZE; x++)
  {
    sum += getValue(array, x); // adds up all the elements in the array
  }

  meanValue = sum / ARRAY_SIZE; //average formula
  return meanValue;
}

/*****+*-****--***------*-*--**---*-****-***--******************************
*
*  Function Information
*
*  Name of Function: standardDeviation
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *array // the array of data to find the standard deviation of
*
*  Function Description: finds the standard deviation of the values in the
*  provided array
*
******+*-****--***------*-*--**---*-****-***--*****************************/
double standardDeviation(int *array)
{
  double stdev; // standard deviation of the array
  double variance; // variance of the array
  double meanValue; // mean of the values
  int x; // used as an index in the for loop
  double sumDifferenceSquares; // sum of X minus x bar, the top part of the standard deviation formula

  // initialize values
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

/*****+*-****--***------*-*--**---*-****-***--******************************
*
*  Function Information
*
*  Name of Function: getValue
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *array // array to get the value from
*    2. int index // index in the array to get the value of
*
*  Function Description: Gets the value in a specified index of an inputted 
*  array.
*
******+*-****--***------*-*--**---*-****-***--*****************************/
int getValue(int *array, int index)
{
  return * (array + index); // aka array[index] but with pointers
}

/*****+*-****--***------*-*--**---*-****-***--******************************
*
*  Function Information
*
*  Name of Function: setValue
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *array // array to modify
*    2. int index // index in the array to modify
*    3. int value // value to set in the specified array
*
*  Function Description: Given an array, an index, and a value, sets the 
*  index in the array to the value specified.
*
******+*-****--***------*-*--**---*-****-***--*****************************/
void setValue(int *array, int index, int value)
{
  * (array + index) = value; // aka array[index] = value; but with pointers
}

/*****+*-****--***------*-*--**---*-****-***--******************************
*
*  Function Information
*
*  Name of Function: outputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double mean // mean of the data set
*    2. double stdev // standard deviation of the data set
*    3. int *data // array of data
*
*  Function Description: Prints to the user the data set's mean, standard
*  deviation, and lists values more than 1 standard deviation away from the
*  mean, both above and below.
*
******+*-****--***------*-*--**---*-****-***--*****************************/
void outputs(double mean, double stdev, int *data)
{
  int x; // index variable for the for loop
  int currentValue; // current value to check for printing above and below stdev

  printf("\n");
  printf("Data set mean: %.1f\n", mean);
  printf("Data set standard deviation: %.1f\n", stdev);

  // data greater than 1 stdev below mean
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

  // data greater than 1 stdev above mean
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