/*****+***-**-**-**-*---*----*--*-*--*******--******************************
*
*  Homework #:
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:
*
******+***-**-**-**-*---*----*--*-*--*******--*****************************/

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

/*****+***-**-**-**-*---*----*--*-*--*******--******************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    N/A
*
*  Function Description: gets the input date as an integer and returns 
*  it to the main function
*
******+***-**-**-**-*---*----*--*-*--*******--*****************************/
int input()
{
  int date; // date the user inputs

  printf("Enter a date in the form MMDDYYYY -> ");
  scanf("%d", &date);

  return date;
}

/*****+***-**-**-**-*---*----*--*-*--*******--******************************
*
*  Function Information
*
*  Name of Function: parseInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int date // date to parse for assignable values
*    2.int *month // address of month in main, stores month value
*    3.int *day // address of day in main, stores day value
*    4. int *year // address of year in main, stores year value
*
*  Function Description: using the known format of the input integer,
*  splits the input into its three parts and assigns those values back to
*  variables in main
*
******+***-**-**-**-*---*----*--*-*--*******--*****************************/
void parseInput(int date, int *month, int *day, int *year) 
{
  // initialize them to 0 otherwise it's basically random numbers
  *month = 0;
  *day = 0;
  *year = 0;

  // last 4 digits go to the year
  *year += 1 * (date % 10);
  date /= 10;

  *year += 10 * (date % 10);
  date /= 10;

  *year += 100 * (date % 10);
  date /= 10;

  *year += 1000 * (date % 10);
  date /= 10;

  // next 2 go to the day
  *day += 1 * (date % 10);
  date /= 10;

  *day += 10 * (date % 10);
  date /= 10;

  // first 2 digits are for the month
  *month += 1 * (date % 10);
  date /= 10;

  *month += 10 * (date % 10);

}

/*****+***-**-**-**-*---*----*--*-*--*******--******************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.int month // month to find the days left in
*    2.int day // current day
*    3.int isLeapYear // used as a boolean, is true if the year inputted by the user is a leap year
*
*  Function Description: calculates the days left in the current month using 
*  the current month and the days left, and factors if it is a leap year into 
*  the calculation.
*
******+***-**-**-**-*---*----*--*-*--*******--*****************************/
int daysLeftInMonth(int month, int day, int isLeapYear)
{
  int daysLeft; // value to return at the end

  // this just makes it easier to read in the if statements to figure out how many days are in the month
  // personally i'd rather read months as their abbreviations rather than their numbers
  // also it really makes the if statements a lot shorter
  int jan;  // is true if the month is january
  int feb;  // is true if the month is february
  int mar;  // is true if the month is march
  int apr;  // is true if the month is april
  int may;  // is true if the month is may
  int jun;  // is true if the month is june
  int jul;  // is true if the month is july
  int aug;  // is true if the month is august
  int sept; // is true if the month is september
  int oct;  // is true if the month is october
  int nov;  // is true if the month is november
  int dec;  // is true if the month is december

  // assigning the month identifiers
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


  // there isn't a 0th day in any month so set it to -1 as an error code if this happens
  if(day == 0)
  {
    daysLeft = -1;
  }
  else if(jan || mar || may || jul || aug || oct || dec) // if it's one of the months with 31 days
  {
    daysLeft = 31 - day;
  } 
  else if(apr || jun || sept || nov) // if its one of the months with 30 days
  {
    daysLeft = 30 - day;
  }
  else if(feb) // if it's february
  {
    if(isLeapYear) // on leap years february has 29 days, if not then 28
    {
      daysLeft = 29 - day;
    }
    else
    {
      daysLeft = 28 - day;
    }
  }
  else // if the month inputted wasnt in the list of months (aka there wasn't at least one of those conditionals that was true) something went wrong, throw an error
  {
    daysLeft = -1;
  }

  return daysLeft;
}

/*****+***-**-**-**-*---*----*--*-*--*******--******************************
*
*  Function Information
*
*  Name of Function: daysLeftInYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month // current month
*    2. int day // current day
*    3. int isLeapYear // used as boolean, true if it's a leap year
*
*  Function Description: calculates how many days are left in the current year
*
******+***-**-**-**-*---*----*--*-*--*******--*****************************/
int daysLeftInYear(int month, int day, int isLeapYear)
{
  int daysLeft; // value to return at the end

  // the year has at least the amount of days left in this month in it
  daysLeft = daysLeftInMonth(month, day, isLeapYear);

  // add up all the days in each month after the current one
  // checks against all of the months, only adds the days if its after the current month
  if(month < 2)
  {
    daysLeft += daysLeftInMonth(2, 1, isLeapYear) + 1; // add 1 because the first day of the month has 1 less day in it than there are days in the month
  }

  if(month < 3)
  {
    daysLeft += daysLeftInMonth(3, 1, isLeapYear) + 1;
  }

  if(month < 4)
  {
    daysLeft += daysLeftInMonth(4, 1, isLeapYear) + 1;
  }

  if(month < 5)
  {
    daysLeft += daysLeftInMonth(5, 1, isLeapYear) + 1;
  }

  if(month < 6)
  {
    daysLeft += daysLeftInMonth(6, 1, isLeapYear) + 1;
  }

  if(month < 7)
  {
    daysLeft += daysLeftInMonth(7, 1, isLeapYear) + 1;
  }

  if(month < 8)
  {
    daysLeft += daysLeftInMonth(8, 1, isLeapYear) + 1;
  }

  if(month < 9)
  {
    daysLeft += daysLeftInMonth(9, 1, isLeapYear) + 1;
  }

  if(month < 10)
  {
    daysLeft += daysLeftInMonth(10, 1, isLeapYear) + 1;
  }

  if(month < 11)
  {
    daysLeft += daysLeftInMonth(11, 1, isLeapYear) + 1;
  }

   if(month < 12)
  {
    daysLeft += daysLeftInMonth(12, 1, isLeapYear) + 1;
  }


  /*
  this would have been so easy...

  month++;
  while(month <= 12)
  {
    daysLeft += daysLeftInMonth(month, 1, isLeapYear) + 1;
    month++;
  }
  */


  return daysLeft;  
}

/*****+***-**-**-**-*---*----*--*-*--*******--******************************
*
*  Function Information
*
*  Name of Function: isALeapYear
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year // the current year
*
*  Function Description: given the year, determines if it's a leap year
*
******+***-**-**-**-*---*----*--*-*--*******--*****************************/
int isALeapYear(int year)
{
  int isLeapYear; // true or false, returns to main at the end

  // selection structure for figuring out if this is a leap year.
  // long story short 97 / 400 years are leap years
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

/*****+***-**-**-**-*---*----*--*-*--*******--******************************
*
*  Function Information
*
*  Name of Function: outputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int daysLeftInMonth // final calculated days left in current month
*    2. int daysLeftInYear // final calculated days left in current year
*
*  Function Description: outputs the results to the command window
*
******+***-**-**-**-*---*----*--*-*--*******--*****************************/
void outputs(int daysLeftInMonth, int daysLeftInYear)
{
  // if the days left in a month is -1, then we know there's an error
  // if the days left in a year are less than 0, its past the end of the year which can't happen
  if((daysLeftInMonth == -1)) 
  {
    printf("\nError: Date entered is not valid!\n");
  }
  else
  {
    printf("\nDays remaining in current month: %d\n", daysLeftInMonth);
    printf("Days remaining in current year: %d\n", daysLeftInYear);
   
  }
}