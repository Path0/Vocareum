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

  number = (pow(n, 2) + n) / 2;

  return number;
}

void inputs(int *odds, int *startingNumber, int *endingNumber)
{
  printf("Enter 0 for even or 1 for odd values -> ");
  scanf("%d", odds);

  printf("Enter starting value -> ");
  scanf("%d", startingNumber);

  printf("Enter ending value -> ");
  scanf("%d", endingNumber);

  printf("\nEven Boiler numbers: ");
}
