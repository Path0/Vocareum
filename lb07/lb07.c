/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Lab #: 7
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Simulates the dealer in a game of blackjack.
*  Takes an integer as input to use as a seed for the random generator
*  function.
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
#include <stdio.h>
#include <stdlib.h>

int cardValue(int, int*);
void printCardName(int);
void printCardSuit(int);
void calculateTotal(int*, int, int*, int*, int*);
void printNominals(int);
void cardLogic(int*, int*, int*, int*, int*, int*);
void inputs();
void dealCards(int*, int*, int*, int*, int*, int*);
void output(int, int);

int main()
{
  int card; // the current card as a number from 0 to 51
  int cardNumber; // nominal value for which card the current card is, eg. first, second, third ...
  int total; // total score at any given moment of all cards in hand
  int num11Aces; // the number of aces that are of value 11
  int hold; // used as boolean, is true if the dealer holds
  int win; // used as boolean, is true if the dealer wins

  inputs();
  
  // sets up initial values
  total = 0;
  cardNumber = 1;
  hold = 0;
  win = 0;

  // game logic
  dealCards(&card, &num11Aces, &hold, &win, &total, &cardNumber);
    
  // shows if the dealer wins, holds, or busts
  output(win, total);

  return 0;
}

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: inputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A
*
*  Function Description: Gets the input seed value for generating random 
*  cards.
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
void inputs()
{
  int seed; // seed value

  // get user input
  printf("Enter the seed value -> ");
  scanf("%d", &seed);
  srand(seed);
}

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: dealCards
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *card // address of card in main, the current card to analyze
*    2. int *num11Aces // address of num11Aces in main, used for keeping 
*       track of how many 11-valued aces are in the dealer's hand
*    3. int *hold // address of hold in main, is true if the dealer holds
*    4. int *win // address of win in main, is true if the dealer wins
*    5. int *total // address of total in main, keeps track of the total score
*    6. int *cardNumber // address of cardNumber in main, keeps track of how
*       many cards are in the dealer's hand
*
*  Function Description: Provides the dealer's logic for getting cards,
*  calculating total score, and if the dealer wins, holds, or busts.
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
void dealCards(int *card, int *num11Aces, int *hold, int *win, int *total, int *cardNumber)
{
  // newline from input
  printf("\n");

  // runs at most 5 times, checks things before running again, otherwise stops
  cardLogic(card, num11Aces, hold, win, total, cardNumber);
  if((*total < 16) && (*hold == 0)) // if the score is less than 16 and the dealer isn't holding then hit with another card
  {
    cardLogic(card, num11Aces, hold, win, total, cardNumber);
    if((*total < 16) && (*hold == 0))
    {
      cardLogic(card, num11Aces, hold, win, total, cardNumber);
      if((*total < 16) && (*hold == 0))
      {
        cardLogic(card, num11Aces, hold, win, total, cardNumber);
        if((*total < 16) && (*hold == 0))
        {
          cardLogic(card, num11Aces, hold, win, total, cardNumber);
        }
      }
    }
  }

  /*
  //it would have been so easy...
  while((total < 16) && (hold == 0) && (cardNumber <= 5))
  {
    cardLogic(&card, &num11Aces, &hold, &win, &total, &cardNumber);
  }
  */
}

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: cardLogic
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *card // address of card in main, the current card to analyze
*    2. int *num11Aces // address of num11Aces in main, used for keeping 
*       track of how many 11-valued aces are in the dealer's hand
*    3. int *hold // address of hold in main, is true if the dealer holds
*    4. int *win // address of win in main, is true if the dealer wins
*    5. int *total // address of total in main, keeps track of the total score
*    6. int *cardNumber // address of cardNumber in main, keeps track of how
*       many cards are in the dealer's hand
*
*  Function Description: Calculates total score and prints to the output
*  which cards the dealer has gotten and their values. 
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
void cardLogic(int *card, int *num11Aces, int *hold, int *win, int *total, int *cardNumber)
{
  int currentCardValue; // value of the card of number *card

  *card = rand() % (52);
  currentCardValue = cardValue(*card, num11Aces);
  calculateTotal(total, currentCardValue, num11Aces, hold, win);

  printf("The ");
  printNominals(*cardNumber);
  printf(" card is #: %d (", (*card + 1)); // add 1 to the card so that card can be from 1-52 instead of 0-51 to match the example output
  printCardName(*card); 
  printf(" of ");
  printCardSuit(*card);
  printf(") Current score: %d\n", *total);

  *cardNumber += 1; // increments cardNumber for nominal printing
}

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: cardValue
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int card // card number between 0 and 51
*    2. int *num11Aces // address of num11Aces in main, keeps track
*       of how many aces the dealer has of value 11
* 
*  Function Description: Determines and returns the value of the card
*  specified, and determines if the card is an ace, adds to the value
*  of *num11Aces.
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
int cardValue(int card, int *num11Aces)
{
  int value;
  int cardTemp;

  cardTemp = card % 13; //suit doesn't matter here
  if(cardTemp == 0) // deals with aces
  {
    value = 11; 
    *num11Aces += 1;
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

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: calculateTotal
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *total // current total score of all cards in the dealer's hand
*    2. int cardValue // current card's value, no need to use pass by address
*       since the value is not needed anywhere but this function
*    3. int *num11Aces // keeps track of how many aces are of value 11 in the 
*       dealer's hand.
*    4. int *hold // is true if the dealer holds
*    5. int *win // is true if the dealer wins
*
*  Function Description: calculates the total score given the current score,
*  a new card, and how many aces there are to swap to value 1 aces. Also determines
*  win conditions and hold conditions.
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
void calculateTotal(int *total, int cardValue, int *num11Aces, int *hold, int *win)
{
  // calculates the new total
  if((*total + cardValue > 21) && (*num11Aces != 0)) // if the value would be over 21 and there is an ace
  {
    *total += cardValue;
    *total -= 10; // turns the 11 ace into a 1 ace
    *num11Aces -= 1; // the number of usable aces goes down 1
  }
  else
  {
    *total += cardValue;
  }
  
  // checks if the dealer should stop drawing cards
  if(*total >= 21)
  {
    *hold = 1;
  }
  
  if(*total == 21) // wins if exactly 21
  {
    *win = 1;
  }
}

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: printNominals
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num // integer representation of the nominal to print, 
*       comes from cardNumber in other functions.
*
*  Function Description: Prints the nominal associated with the inputted
*  integer, between 1 and 5.
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
void printNominals(int num) 
{
  switch(num)
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
    default:
      break;
  }
}

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: printCardName
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int card // card to analyze
*
*  Function Description: Prints the name of the card given the current card
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
void printCardName(int card)
{
  card %= 13; // suit doesn't matter here, modulus just makes it easier
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
    
  if((card > 0) && (card <= 9)) // if it's just a number card print the number plus 1
  {
    printf("%d", (card + 1)); // card 9 is a 10 because 0-51 to 1-52 value conversion
  }

}

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: printCardSuit
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int card // current card to analyze
*
*  Function Description: Given the current card, prints the suit the card
*  belongs to.
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
void printCardSuit(int card)
{
  switch(card / 13) // card / 13 gives either 0, 1, 2, or 3 if it's from 0-13, 14-26, 27-39, or 40-52
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

/*****+*-*-*--**-*------*-*-***-*---**-*****--******************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int win // is true if the dealer wins
*    2. int total // total score
*
*  Function Description: Outputs final result given win status and total score
*
******+*-*-*--**-*------*-*-***-*---**-*****--*****************************/
void output(int win, int total)
{
  if(win) // if they win print they win wow cool
  {
    printf("\nDealer wins!\n");
  }
  else if(total > 21) // win is false but the total is over 21 they bust
  {
    printf("\nDealer busts.\n");
  }
  else // if win is false and total is less than 21 they hold
  {
    printf("\nDealer holds.\n");
  }   
}