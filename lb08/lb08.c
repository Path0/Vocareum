#include <stdio.h>
#include <math.h>

void inputs(int*);
int changes(long*);
void outputs(int);

int main()
{
  int sequence;

  inputs(&sequence);

  outputs(changes(sequence));
}

void inputs(int *sequence)
{
  printf("Enter the initial configuration -> ");
  scanf("%ld", sequence);
  printf("\n");
}

int changes(long *sequence)
{
  int numChanges;
  int length;
  int x;
  int previousNumber;
  int currentNumber;
  int y;

  numChanges = 0;

  length = log10(*sequence) + 1;

  for(y = 0; y < length; y++)
  {
    *sequence -= pow(10, y);
  }
  printf("%ld", *sequence);

  currentNumber = *sequence % 10;
  previousNumber = !currentNumber;

  for(x = 2; x <= length + 1; x++)
  {
    currentNumber = *sequence % 10;

    if(currentNumber == previousNumber)
    {
      numChanges++;
      previousNumber = !previousNumber;
    }
    else
    {
      previousNumber = currentNumber;
    }

    *sequence /= 10;
    
  }
  
  return numChanges;
}

void outputs(int numChanges)
{
  printf("Fewest # of required changes: %d\n", numChanges);
}