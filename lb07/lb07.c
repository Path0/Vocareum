#include <stdio.h>
#include <stdlib.h>

int cardValue(int, int*);
void printCardName(int);
void printCardSuit(int);
void calculateTotal(int*, int, int*, int*, int*);
void printNominals(int);
int main()
{


  int seed;
  int num11Aces;
  int hold;
  int win;
  int card;
  int total;
  int cardNumber;
  int currentCardValue;

  printf("Enter the seed value -> ");
  scanf("%d", &seed);  

  srand(seed);

  total = 0;
  cardNumber = 1;
  hold = 0;
  win = 0;

  printf("\n");
  while((total < 17) && (hold == 0))
  {
    card = rand() % (52);
    currentCardValue = cardValue(card, &num11Aces);
    calculateTotal(&total, currentCardValue, &num11Aces, &hold, &win);

    if(hold) // if the total is too high don't print anything
    {
      continue;
    }

    printf("The ");
    printNominals(cardNumber);
    printf(" card is #: %d (", (card + 1));
    printCardName(card);
    printf(" of ");
    printCardSuit(card);
    printf(") Current score: %d\n", total);

    cardNumber++;
  }

  if(win)
  {
    printf("\nDealer wins!");
  }
  else
  {
    printf("\nDealer holds.");
  }


  return 0;
}

int cardValue(int card, int *num11Aces)
{
  int value;
  int cardTemp;

  cardTemp = card % 13; //suit doesn't matter here
  if(cardTemp == 0) // deals with aces
  {
    value = 11; 
    *num11Aces++;
  }
  else if(cardTemp > 9) // deals with face cards
  {
    value = 10;
  }
  else // everything else (number cards)
  {
    value = cardTemp + 1;
  }


  return value;
}

void printCardName(int card)
{
  card %= 13; // suit doesn't matter here
  switch(card)
  {
    case 0:
      printf("Ace");
      break;
    case 10:
      printf("Jack");
      break;
    case 11:
      printf("Queen");
      break;
    case 12:
      printf("King");
      break;
    default:
      break;
  }
    
  if((card > 0) && (card <= 9))
  {
    printf("%d", (card + 1));
  }

}

void printCardSuit(int card)
{
  switch(card / 13)
  {
    case 0:
      printf("Clubs");
      break;
    case 1:
      printf("Diamonds");
      break;
    case 2:
      printf("Hearts");
      break;
    case 3:
      printf("Spades");
      break;
    default:
      break;
  }
}

void calculateTotal(int *total, int cardValue, int *num11Aces, int *hold, int *win)
{
  if((*total + cardValue > 21) && (*num11Aces != 0)) // if the value would be over 21 and there is an ace
  {
    *total += cardValue;
    *total -= 10; // turns the 11 ace into a 1 ace
    *num11Aces -= 1; // the number of usable aces goes down 1
    *hold = 1;
  }
  else
  {
    *total += cardValue;
  }

  if(*total >= 21)
  {
    *hold = 1;
  }
  
  if(*total == 21)
  {
    *win = 1;
  }
}

void printNominals(int num) 
{
  switch(num) // the worst possible hand is 4 aces, 4 2's and 2 3's so the max number of cards is 10 in any dealer game ever
  {
    case 1:
      printf("first");
      break;
    case 2:
      printf("second");
      break;
    case 3:
      printf("third");
      break;
    case 4:
      printf("fourth");
      break;
    case 5:
      printf("fifth");
      break;
    case 6:
      printf("sixth");
      break;
    case 7:
      printf("seventh");
      break;
    case 8:
      printf("eighth");
      break;
    case 9:
      printf("ninth");
      break;
    case 10:
      printf("tenth");
      break;
    default:
      break;
  }
}
