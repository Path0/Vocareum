#include <stdio.h>

void inputs(int*);

int main()
{
  int sequence;

  inputs(&sequence);
}

void inputs(int *sequence)
{
  printf("Enter the initial configuration -> ");
  scanf("%ld", sequence);
  printf("\n");
}