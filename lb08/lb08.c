/*****+*****--*****---*---*-***-----**-*****--******************************
*
*  Lab #:
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description:
*
******+*****--*****---*---*-***-----**-*****--*****************************/

#include <stdio.h>
#include <math.h>

long inputs();
int checkInput(long);
int changes(long*);
void outputs(int);

int main()
{
  long sequence; // sequence to analyze

  sequence = inputs();
  outputs(changes(&sequence)); // changes gives the number of changes required, outputs takes in the number of changes required. Why waste a filler variable when you could just do this

  return 0;
}

/*****+*****--*****---*---*-***-----**-*****--******************************
*
*  Function Information
*
*  Name of Function: inputs
*
*  Function Return Type: long
*
*  Parameters (list data type, name, and comment one per line):
*    N/A
*
*  Function Description: Gets user input for sequence to analyze. Returns 
*  the user's value to be used in other functions.
*
******+*****--*****---*---*-***-----**-*****--*****************************/
long inputs()
{
  long sequence; // sequence of 1's and 2's
  int error; // is true if there is an error

  printf("Enter the initial configuration -> ");
  scanf("%ld", &sequence);
  printf("\n");

  // determines if the initial input has an error
  error = checkInput(sequence);

  // if it has an error, and while it continues to have an error, keeps asking the user to input another sequence
  while(error)
  {
    printf("Error! Input must contain only digits 1 and 2!\n");

    printf("\nEnter the initial configuration -> ");
    scanf("%ld", &sequence);
    printf("\n");

    error = checkInput(sequence); // rechecks if the new sequence has an error
  }
  return sequence;
}

/*****+*****--*****---*---*-***-----**-*****--******************************
*
*  Function Information
*
*  Name of Function: checkInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. long seq // sequence to check if it is valid
*
*  Function Description: given a sequence of numbers, determines if the
*  sequence contains only 1's and 2's. Returns 1 if the input sequence is 
*  invalid, 0 if it is valid.
*
******+*****--*****---*---*-***-----**-*****--*****************************/
int checkInput(long seq)
{
  int invalid; // used as boolean, is true if the sequence is invalid
  long sequence; // sequence to test
  int length; // length of the inputted sequence
  int x; // used in for loop as an index
  int currentNumber; // used in for loop to store the number value in the digit being looked at

  // set up initial values
  invalid = 0; 
  sequence = seq;
  length = log10(sequence) + 1;

  for(x = 0; x < length; x++)
  {
    currentNumber = sequence % 10;

    // for each digit, check if it's only 1's and 2's. If it contains a number other than 1 or 2, sets the sequence to be invalid
    if((currentNumber != 1) && (currentNumber != 2)) 
    {
      invalid = 1;
    }

    sequence /= 10;
  }
  return invalid;
}

/*****+*****--*****---*---*-***-----**-*****--******************************
*
*  Function Information
*
*  Name of Function: changes
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. long *sequence
*
*  Function Description: Determines the number of changes in a sequence of
*  1's and 2's to make it so that the sequence is alternating.
*
******+*****--*****---*---*-***-----**-*****--*****************************/
int changes(long *sequence)
{
  int numChanges; // number of changes needed
  int length; // length of inputted sequence
  int x; // used in for loop as an index variable
  int previousNumber; // previous number in sequence
  int currentNumber; // curent number to analyze in the sequence
  int seqReverse; // stores the sequence reversed
  int seqCopy; // copy of the sequence, for reversal purposes
  int lastDigit; // last digit of the sequence, used for reversal
  int numReverseChanges; // number of changes required in the reversed sequence

  numChanges = 0;

  length = log10(*sequence) + 1;

  currentNumber = (*sequence % 10) - 1; // current number is the last digit of the sequence, subtract 1 to make it either a 0 or a 1
  previousNumber = !currentNumber; // assume the "previous" digit is the opposite of the current digit

  for(x = 0; x < length; x++)
  {
    currentNumber = (*sequence % 10) - 1; // doing math on 0's and 1's is easier than 1's and 2's so subtract 1 from every number in the sequence as it comes up

    if(currentNumber == previousNumber) // if it isn't alternating (11 or 22), add 1 to the number of changes
    {
      numChanges++;
      previousNumber = !previousNumber; // set the previous number to what it would be if it were already alternating
    }
    else // otherwise it's already alternating so just change previousNumber to the opposite of it, which is currentNumber
    {
      previousNumber = currentNumber;
    }

    *sequence /= 10;
    
  }

  //check it the other way, front to back

  // setup for reversal
  seqCopy = *sequence;
  seqReverse = 0;
  numReverseChanges = 0;

  // reverse the sequence
  for(x = 0; x < length; x++)
  {
    // basically moves the last digit to the front repeatedly
    lastDigit = seqCopy % 10;
    seqReverse = (seqReverse * 10) + lastDigit;
  }

  // do the checking for changes process again but with the reversed sequence
  currentNumber = (seqReverse % 10) - 1;
  previousNumber = !currentNumber;

  for(x = 0; x < length; x++)
  {
    currentNumber = (seqReverse % 10) - 1;

    if(currentNumber == previousNumber)
    {
      numReverseChanges++;
      previousNumber = !previousNumber;
    }
    else
    {
      previousNumber = currentNumber;
    }
    seqReverse /= 10;
  }

  // sets numChanges to the lower of numChanges and numReverseChanges.
  if(numReverseChanges < numChanges)
  {
    numChanges = numReverseChanges;
  }

  return numChanges;
}

/*****+*****--*****---*---*-***-----**-*****--******************************
*
*  Function Information
*
*  Name of Function: outputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int numChanges // smallest number of changes to make
*
*  Function Description: Outputs to console the number of changes needed to 
*  make an alternating sequence.
*
******+*****--*****---*---*-***-----**-*****--*****************************/
void outputs(int numChanges)
{
  printf("Fewest # of required changes: %d\n", numChanges);
}