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
  long sequence;
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
  int seqReverse;
  int seqCopy;
  int lastDigit;
  int numReverseChanges;

  numChanges = 0;

  length = log10(*sequence) + 1;

  currentNumber = (*sequence % 10) - 1;
  previousNumber = !currentNumber;

  for(x = 0; x < length; x++)
  {
    currentNumber = (*sequence % 10) - 1;

    if(currentNumber == previousNumber)
    {
      printf("%d - %d\n", currentNumber, previousNumber);
      numChanges++;
      previousNumber = !previousNumber;
    }
    else
    {
      printf("%d - %d\n", currentNumber, previousNumber);
      previousNumber = currentNumber;
    }

    *sequence /= 10;
    
  }

  //check it the other way, front to back
  // https://medium.com/@ManBearPigCode/how-to-reverse-a-number-mathematically-97c556626ec6

  seqCopy = *sequence;
  seqReverse = 0;
  numReverseChanges = 0;

  for(x = 0; x < length; x++)
  {
    lastDigit = seqCopy % 10;
    seqReverse = (seqReverse * 10) + lastDigit;
  }

  currentNumber = (seqReverse % 10) - 1;
  previousNumber = !currentNumber;

  for(x = 0; x < length; x++)
  {
    currentNumber = (seqReverse % 10) - 1;

    if(currentNumber == previousNumber)
    {
      printf("%d - %d\n", currentNumber, previousNumber);
      numReverseChanges++;
      previousNumber = !previousNumber;
    }
    else
    {
      printf("%d - %d\n", currentNumber, previousNumber);
      previousNumber = currentNumber;
    }

    seqReverse /= 10;
    
  }

  if(numReverseChanges < numChanges)
  {
    numChanges = numReverseChanges;
  }

  
  return numChanges;
}

void outputs(int numChanges)
{
  printf("Fewest # of required changes: %d\n", numChanges);
}