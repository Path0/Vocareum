#include <stdio.h>
#include <math.h>

int boilerNumber(int);
void inputs(int*, int*, int*);

int main()
{
  int odds;
  int startingNumber;
  int endingNumber;
  int x;
  int currentBoilerNumber;

  inputs(&odds, &startingNumber, &endingNumber);

  if(odds)
  {
    printf("\nOdd Boiler numbers: ");
  }
  else
  {
    
    printf("\nEven Boiler numbers: ");
  }

  for(x = startingNumber; x <= endingNumber; x++)
  {
    currentBoilerNumber = boilerNumber(x);

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
  printf("\n");
  return 0;
}

int boilerNumber(int n)
{
  int number;

  number = (pow(n, 2) + n) / 2; // this is equivalent to summing all integers from 1 to n. 

  return number;
}

void inputs(int *odds, int *startingNumber, int *endingNumber)
{
  printf("Enter 0 for even or 1 for odd values -> ");
  scanf("%d", odds);
  
  while((*odds != 0) && (*odds != 1))
  {
    printf("\nError! Select a valid option!!\n\n");

    printf("Enter 0 for even or 1 for odd values -> ");
    scanf("%d", odds);
  }

  printf("Enter starting value -> ");
  scanf("%d", startingNumber);

  while(*startingNumber < 1)
  {
    printf("\nError! Starting value must be positive!\n\n");

    printf("Enter starting value -> ");
    scanf("%d", startingNumber);
  }

  printf("Enter ending value -> ");
  scanf("%d", endingNumber);

  while(*endingNumber <= *startingNumber)
  {
    printf("Error! Ending value must be > %d", *startingNumber);

    printf("Enter ending value -> ");
    scanf("%d", endingNumber);

  }

  
}
