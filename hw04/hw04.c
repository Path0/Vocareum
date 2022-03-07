#include "stdio.h"
#include "math.h"

int input();
void parseInput(int, int*, int*, int*);
int daysLeftInMonth(int, int, int);
int daysLeftInYear(int, int, int);
int isALeapYear(int);
void outputs(int, int);

int main()
{
  int inputDate;
  int month;
  int day;
  int year;

  int isLeapYear;
  
  int daysLeftMonth;
  int daysLeftYear;
  
  

  inputDate = input();

  parseInput(inputDate, &month, &day, &year);

  isLeapYear = isALeapYear(year);

  daysLeftMonth = daysLeftInMonth(month, day, isLeapYear);
  daysLeftYear = daysLeftInYear(month, day, isLeapYear);

  outputs(daysLeftMonth, daysLeftYear);

  return 0;
}


int input()
{
  int date;

  printf("Enter a date in the form MMDDYYYY -> ");
  scanf("%d", &date);

  return date;
}

void parseInput(int date, int *month, int *day, int *year) 
{
  *month = 0;
  *day = 0;
  *year = 0;

  *year += 1 * (date % 10);
  date /= 10;

  *year += 10 * (date % 10);
  date /= 10;

  *year += 100 * (date % 10);
  date /= 10;

  *year += 1000 * (date % 10);
  date /= 10;

  *day += 1 * (date % 10);
  date /= 10;

  *day += 10 * (date % 10);
  date /= 10;

  *month += 1 * (date % 10);
  date /= 10;

  *month += 10 * (date % 10);

}

int daysLeftInMonth(int month, int day, int isLeapYear)
{
  int daysLeft;

  int jan;
  int feb;
  int mar;
  int apr;
  int may;
  int jun;
  int jul;
  int aug;
  int sept;
  int oct;
  int nov;
  int dec;

  jan = (month == 1);
  feb = (month == 2);
  mar = (month == 3);
  apr = (month == 4);
  may = (month == 5);
  jun = (month == 6);
  jul = (month == 7);
  aug = (month == 8);
  sept = (month == 9);
  oct = (month == 10);
  nov = (month == 11);
  dec = (month == 12);


  if(jan || mar || may || jul || aug || oct || dec)
  {
    daysLeft = 31 - day;
  } 
  else if(apr || jun || sept || nov)
  {
    daysLeft = 30 - day;
  }
  else if(feb)
  {
    if(isLeapYear)
    {
      daysLeft = 29 - day;
    }
    else
    {
      daysLeft = 28 - day;
    }
  }
  else
  {
    daysLeft = -1;
  }

  return daysLeft;
}

int daysLeftInYear(int month, int day, int isLeapYear)
{
  int daysLeft;
  daysLeft = daysLeftInMonth(month, day, isLeapYear);

  month++;

  while(month <= 12){
    daysLeft += daysLeftInMonth(month, 0, isLeapYear);
    month++;
  }


  return daysLeft;  
}

int isALeapYear(int year)
{
  int isLeapYear;

  if(year % 4 != 0)
  {
    isLeapYear = 0;
  }
  else if(year % 100 != 0)
  {
    isLeapYear = 1;
  }
  else if(year % 400 != 0)
  {
    isLeapYear = 0;
  }
  else
  {
    isLeapYear = 1;
  }

  return isLeapYear;
}

void outputs(int daysLeftInMonth, int daysLeftInYear)
{
  if((daysLeftInMonth == -1) || (daysLeftInYear < 0) || (daysLeftInMonth < 0) || (daysLeftInMonth > 30)) 
  {
    printf("\nError: Date entered is not valid!\n");
  }
  else
  {
    printf("\nDays remaining in current month: %d\n", daysLeftInMonth);
    printf("Days remaining in current year: %d\n", daysLeftInYear);
   
  }
}