#include <stdio.h>
#include <math.h>

void inputs(int*);
int changes(long);

int main()
{
  int sequence;

  inputs(&sequence);

  changes(sequence);
}

void inputs(int *sequence)
{
  printf("Enter the initial configuration -> ");
  scanf("%ld", sequence);
  printf("\n");
}

int changes(long sequence)
{
  int numChanges;
  int length;
  int x;
  int previousNumber;
  int currentNumber;

  length = log10(sequence) + 1;

  currentNumber = sequence % 10;
  previousNumber = !currentNumber;

  for(x = 2; x <= length + 1; x++)
  {
    currentNumber = sequence % (x * 10);
    
  }
  
  return numChanges;
}