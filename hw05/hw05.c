/*****+***-*--**-*--*-*-*----**-----**-*****--******************************
*
*  Homework #: 5
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Given a user-inputted range of integers and a selection
*  of either even or odd numbers, prints every boiler number in that rance
*  that is either even or odd. Returns an error if none meeting the criteria
*  found.
*
******+***-*--**-*--*-*-*----**-----**-*****--*****************************/
#include <stdio.h>
#include <math.h>

void inputs(int*, int*, int*);
void printNumbers(int, int, int);
int boilerNumber(int);

int main()
{
  int odds; // used as boolean, is true if the user wants odd boiler numbers, is false if they want evens
  int startingNumber; // starting number in range of numbers to check
  int endingNumber; // ending number in range of numbers to check
  
  inputs(&odds, &startingNumber, &endingNumber);
  printNumbers(odds, startingNumber, endingNumber);
  
  return 0;
}

/*****+***-*--**-*--*-*-*----**-----**-*****--******************************
*
*  Function Information
*
*  Name of Function: printNumbers
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int odds // used as boolean, is true if the user wants odd numbers
*    2. int startingNumber // starting number in range to check
*    3. int endingNumber // ending number in range to check
*
*  Function Description: Given if the user wants odds or evens, and the range
*  to check, prints boiler numbers that meet those criteria.
*
******+***-*--**-*--*-*-*----**-----**-*****--*****************************/
void printNumbers(int odds, int startingNumber, int endingNumber)
{
  int x; // used in for loop as an index
  int currentBoilerNumber; // current boiler number to determine whether to print or not

  if((endingNumber - startingNumber) != 1) // only prints these if its not consecutive, if it is, it prints later
  {
    if(odds)
    {
      printf("\nOdd Boiler numbers: ");
    }
    else
    {  
      printf("\nEven Boiler numbers: ");
    }
  }
  
  // for every number between and including the starting and ending number, find the boiler number associated 
  // with it and print if it's even or odd depending on the user's input
  for(x = startingNumber; x <= endingNumber; x++)
  {
    currentBoilerNumber = boilerNumber(x);

    if((endingNumber - startingNumber) == 1) // if theyre consecutive then don't do anything just stop the loop and keep going
    {
      break;
    }

    if(odds)
    {
      if(currentBoilerNumber % 2 == 1)
      {
        printf("%d ", currentBoilerNumber);
      }
    }
    else
    {
      if(currentBoilerNumber % 2 == 0)
      {
        printf("%d ", currentBoilerNumber);
      }
    }
    
  }

  // if it's two consecutive numbers, for each set either evens or odds are invalid and should show an error
  if((endingNumber - startingNumber) == 1)
  {
    currentBoilerNumber = boilerNumber(startingNumber);
    if(odds)
    {
      if(currentBoilerNumber % 2 == 1) // if the boiler number is odd and the user wants odd numbers, print it. otherwise give an error 
      {
        printf("\nOdd Boiler numbers: ");
        printf("%d ", currentBoilerNumber);
      }
      else
      {
        printf("\nError: No values generated.");
      }
    }
    else
    {
      if(currentBoilerNumber % 2 == 0)
      {
        printf("\nEven Boiler numbers: ");
        printf("%d ", currentBoilerNumber);
      }
      else
      {
        printf("\nError: No values generated.");
      }
    }
  }

  printf("\n");
}

/*****+***-*--**-*--*-*-*----**-----**-*****--******************************
*
*  Function Information
*
*  Name of Function: boilerNumber
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int n // number to find the boiler number associated with
*
*  Function Description: Finds the boiler number (sum of all integers from 1 to
*  n) for the integer inputted
*
******+***-*--**-*--*-*-*----**-----**-*****--*****************************/
int boilerNumber(int n)
{
  int number; // stores boiler number to return to other functions

  number = (pow(n, 2) + n) / 2; // this is equivalent to summing all integers from 1 to n. 

  return number;
}

/*****+***-*--**-*--*-*-*----**-----**-*****--******************************
*
*  Function Information
*
*  Name of Function: inputs
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *odds // is true if user wants odd numbers
*    2. int *startingNumber // starting number in range
*    3. int *endingNumber // ending number in range
*
*  Function Description: Gets user input, and validates input. 
*
******+***-*--**-*--*-*-*----**-----**-*****--*****************************/
void inputs(int *odds, int *startingNumber, int *endingNumber)
{

  printf("Enter 0 for even or 1 for odd values -> ");
  scanf("%d", odds);
  
  // if the user input isn't right then keeps asking for a new input until it is right
  while((*odds != 0) && (*odds != 1))
  {
    printf("\nError! Select a valid option!!\n\n");

    printf("Enter 0 for even or 1 for odd values -> ");
    scanf("%d", odds);
  }

  printf("Enter starting value -> ");
  scanf("%d", startingNumber);

  // if the user input isn't right then keeps asking for a new input until it is right
  while(*startingNumber < 1)
  {
    printf("\nError! Starting value must be positive!\n\n");

    printf("Enter starting value -> ");
    scanf("%d", startingNumber);
  }

  printf("Enter ending value -> ");
  scanf("%d", endingNumber);

  // if the user input isn't right then keeps asking for a new input until it is right
  while(*endingNumber <= *startingNumber)
  {
    printf("\nError! Ending value must be > %d\n\n", *startingNumber);

    printf("Enter ending value -> ");
    scanf("%d", endingNumber);

  }
}
