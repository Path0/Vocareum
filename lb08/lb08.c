#include <stdio.h>
#include <math.h>

long inputs();
int changes(long*);
void outputs(int);

int main()
{
  long sequence;

  sequence = inputs();

  

  outputs(changes(&sequence));
  
  return 0;
}

long inputs()
{
  long sequence;
  printf("Enter the initial configuration -> ");
  scanf("%ld", &sequence);
  printf("\n");
  return sequence;
}

int changes(long *sequence)
{
  int numChanges;
  int length;
  int x;
  int previousNumber;
  int currentNumber;

  numChanges = 0;

  length = log10(*sequence) + 1;

  currentNumber = (*sequence % 10) - 1;
  previousNumber = !currentNumber;

  for(x = 2; x <= length + 1; x++)
  {
    currentNumber = (*sequence % 10) - 1;
    //printf("\n%d\n", *sequence);

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