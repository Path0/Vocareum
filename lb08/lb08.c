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
  int length;
  int x;
  int sequenceCopy;
  int error;

  printf("Enter the initial configuration -> ");
  scanf("%ld", &sequence);
  printf("\n");
  
  // check inputs for anything but 1 and 2
  sequenceCopy = sequence;
  length = log10(sequenceCopy) + 1;

  for(x = 0; x < length; x++)
  {
    if((sequenceCopy % 10 != 1) && (sequenceCopy % 10 != 2))
    {
      error = 1;
    }
  }
  while(error)
  {
    printf("Error! Input must contain only digits 1 and 2!\n");
    error = 0;

    printf("Enter the initial configuration -> ");
    scanf("%ld", &sequence);
    printf("\n");

    for(x = 0; x < length; x++)
    {
      if((sequenceCopy % 10 != 1) && (sequenceCopy % 10 != 2))
      {
        error = 1;
      }
    }
    
  }
  
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