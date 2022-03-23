#include <stdio.h>
#include <math.h>

long inputs();
int checkInput(long);
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
  int error;

  printf("Enter the initial configuration -> ");
  scanf("%ld", &sequence);
  printf("\n");

  error = checkInput(sequence);
  printf("%d\n", error);

  while(error)
  {
    printf("Error! Input must contain only digits 1 and 2!\n");

    printf("\nEnter the initial configuration -> ");
    scanf("%ld", &sequence);
    printf("\n");

    error = checkInput(sequence);
  }
  
  
  
  return sequence;
}

int checkInput(long seq)
{
  int invalid;
  int sequence;
  int length;
  int x;
  int currentNumber;

  invalid = 0;
  sequence = seq;

  length = log10(sequence) + 1;

  for(x = 0; x < length; x++)
  {
    currentNumber = sequence % 10;

    if((currentNumber != 1) && (currentNumber != 2))
    {
      invalid = 1;
    }

    sequence /= 10;
  }

  return invalid;
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

  for(x = 0; x < length; x++)
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