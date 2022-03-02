/*****+******-**-*--*-----*-***-----********--******************************
*
*  Lab #: 6
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Calculates the largest and smallest possible areas
*  of triangles given 4 sides to make combinations of, and prints the sides
*  used when making the areas.
*
******+******-**-*--*-----*-***-----********--*****************************/

#include "stdio.h"
#include "math.h"

void inputs(double*, double*, double*, double*);
double area(double, double, double);
void largestArea(double, double, double, double, int*, int*, int*, int*, int*);
void smallestArea(double, double, double, double, int*, int*, int*, int*, int*);
void outputs(double, double, double, double, double, double, double, double, int, int, int, int, int, int, int, int, int);

int main()
{
  double side1; // side 1, user input
	double side2; // side 2, user input
	double side3; // side 3, user input
	double side4; // side 4, user input

  double area123; // area of the triangle containing sides 1, 2, and 3
	double area124; // area of the triangle containing sides 1, 2, and 4
	double area134; // area of the triangle containing sides 1, 3, and 4
	double area234; // area of the triangle containing sides 2, 3, and 4

	int area123_largest; // used as boolean, is true if area123 is the largest area out of the possibilities
	int area124_largest; // used as boolean, is true if area124 is the largest area out of the possibilities
	int area134_largest; // used as boolean, is true if area134 is the largest area out of the possibilities
	int area234_largest; // used as boolean, is true if area234 is the largest area out of the possibilities

	int area123_smallest; // used as boolean, is true if area123 is the smallest area out of the possibilities
	int area124_smallest; // used as boolean, is true if area124 is the smallest area out of the possibilities
	int area134_smallest; // used as boolean, is true if area134 is the smallest area out of the possibilities
	int area234_smallest; // used as boolean, is true if area234 is the smallest area out of the possibilities

	int error; // used as boolean, is true if either largestArea or smallestArea errors out. causes outputs() to print the error statement

	// gets inputs
	inputs(&side1, &side2, &side3, &side4);

  // assigns areas
	area123 = area(side1, side2, side3);
	area124 = area(side1, side2, side4);
	area134 = area(side1, side3, side4);
	area234 = area(side2, side3, side4);

  // finds largest and smallest areas and edits the boolean values to reflect this
	largestArea(area123, area124, area134, area234, &area123_largest, &area124_largest, &area134_largest, &area234_largest, &error);
	smallestArea(area123, area124, area134, area234, &area123_smallest, &area124_smallest, &area134_smallest, &area234_smallest, &error);

	// prints results to command window
	outputs(area123, area124, area134, area234, side1, side2, side3, side4, area123_largest, area124_largest, area134_largest, area234_largest, area123_smallest, area124_smallest, area134_smallest, area234_smallest, error);

  return 0;
}

/*****+***-**-**-*--*-----*-***-----********--******************************
*
*  Function Information
*
*  Name of Function: inputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double *side1 // address of side 1 to save the inputted value to
*    2. double *side2 // address of side 2 to save the inputted value to
*    3. double *side3 // address of side 3 to save the inputted value to
*    4. double *side4 // address of side 4 to save the inputted value to
*
*  Function Description: gets inputs from user and stores them in memory
*
******+***-**-**-*--*-----*-***-----********--*****************************/
void inputs(double *side1, double *side2, double *side3, double *side4)
{
	// get side 1
	printf("Enter length of side #1 -> ");
	scanf("%lf", side1);

  // get side 2
	printf("Enter length of side #2 -> ");
	scanf("%lf", side2);

  // get side 3
	printf("Enter length of side #3 -> ");
	scanf("%lf", side3);

  // get side 4
	printf("Enter length of side #4 -> ");
	scanf("%lf", side4);
}

/*****+***-**-**-*--*-----*-***-----********--******************************
*
*  Function Information
*
*  Name of Function: area
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double side1 // first side of triangle
*    2. double side2 // second side of triangle
*    3. double side3 // third side of triangle
*
*  Function Description: calculates area of a triangle given 3 side lengths
*  using Heron's formula. returns the area as 0 if the sides are invalid and
*  cannot form a triangle
*
******+***-**-**-*--*-----*-***-----********--*****************************/
double area(double side1, double side2, double side3)
{
	double perimeter_over_2; // s in heron's formula, perimeter divided by 2
	double area; // final calculated area

  // super long conditional to find out if 2 of the sides don't add up to the third, checks all three possible cases
	if(((side1 + side2) <= side3) || ((side2 + side3) <= side1) || ((side3 + side1) <= side2))
	{
		area = 0; // sets the area to 0 for identifying purposes then exits the function here
		return area;
	}

	perimeter_over_2 = (side1 + side2 + side3) / 2;
	area = sqrt(perimeter_over_2 * (perimeter_over_2 - side1) * (perimeter_over_2 - side2) * (perimeter_over_2 - side3));
	
	return area;

}

/*****+***-**-**-*--*-----*-***-----********--******************************
*
*  Function Information
*
*  Name of Function: largestArea
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double area1 // first area to see if it's the largest
*    2. double area2 // second area to see if it's the largest
*    3. double area3 // third area to see if it's the largest
*    4. double area4 // fourth area to see if it's the largest
*    5. int *area1_largest // used as a boolean value, is true if area 1 is the largest area of the areas inputted
*    6. int *area2_largest // used as a boolean value, is true if area 2 is the largest area of the areas inputted
*    7. int *area3_largest // used as a boolean value, is true if area 3 is the largest area of the areas inputted
*    8. int *area4_largest // used as a boolean value, is true if area 4 is the largest area of the areas inputted
*    9. int *error // used as a boolean value, is true if all of the areas are 0 (if none of the triangles are valid from the area function returning 0)
*
*  Function Description: given 4 areas, figures out which is the largest and saves the cooresponding identifier to be true for use in other functions
*
******+***-**-**-*--*-----*-***-----********--*****************************/
void largestArea(double area1, double area2, double area3, double area4, int *area1_largest, int *area2_largest, int *area3_largest, int *area4_largest, int *error)
{
	double max; // initialize max value of area to find out which area is the largest

  // set them all to 0 to start with, mess with them later
	*area1_largest = 0;
	*area2_largest = 0;
	*area3_largest = 0;
	*area4_largest = 0;	

  // as long as area1 isn't 0, we can assume it's the max and check from there
	if(area1 != 0)
	{
		max = area1;

		*area1_largest = 1;
	}

	// checks if area2 is bigger than the current max
	if(area2 > max)
	{
		max = area2;

    // we have to reassign the others back to 0 or else they might get written over later and more than one could be classified as the largest
		*area1_largest = 0;
		*area2_largest = 1;
		*area3_largest = 0;
		*area4_largest = 0;
	}

	// checks if area3 is bigger than the current max
	if(area3 > max)
	{
		max = area3;

		*area1_largest = 0;
		*area2_largest = 0;
		*area3_largest = 1;
		*area4_largest = 0;
	}

  // checks if area4 is bigger than the current max
	if(area4 > max)
	{
		max = area4;

		*area1_largest = 0;
		*area2_largest = 0;
		*area3_largest = 0;
		*area4_largest = 1;
	}

	// if they're all 0, then all the area functions said that the triangles are invalid, so throw an error to print the thing that's like "no possible triangles"
	if((area1 == 0) && (area2 == 0) && (area3 == 0) && (area4 == 0))
	{
		*error = 1;
	}

	return;
} 

/*****+***-**-**-*--*-----*-***-----********--******************************
*
*  Function Information
*
*  Name of Function: smallestArea
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double area1 // first area to see if it's the smallest
*    2. double area2 // second area to see if it's the smallest
*    3. double area3 // third area to see if it's the smallest
*    4. double area4 // fourth area to see if it's the smallest
*    5. int *area1_smallest // used as a boolean value, is true if area 1 is the smallest area of the areas inputted
*    6. int *area2_smallest // used as a boolean value, is true if area 2 is the smallest area of the areas inputted
*    7. int *area3_smallest // used as a boolean value, is true if area 3 is the smallest area of the areas inputted
*    8. int *area4_smallest // used as a boolean value, is true if area 4 is the smallest area of the areas inputted
*    9. int *error // used as a boolean value, is true if all of the areas are 0 (if none of the triangles are valid from the area function returning 0)
*
*  Function Description:
*
******+***-**-**-*--*-----*-***-----********--*****************************/
void smallestArea(double area1, double area2, double area3, double area4, int *area1_smallest, int *area2_smallest, int *area3_smallest, int *area4_smallest, int *error)
{
	double min; // minimum value

	// initialize them all to 0 to reassign later
	*area1_smallest = 0;
	*area2_smallest = 0;
	*area3_smallest = 0;
	*area4_smallest = 0;

	min = area1 + area2 + area3 + area4 + 1; //set the min to the largest possible sum of areas plus one so it's the highest thing it could possibly compare against, plus one.

	// as long as area1 isn't 0, we can assume it's the min and check from there
	if(area1 != 0)
	{
		min = area1;
		*area1_smallest = 1;
	}

	// checks if area2 is less than the current min and it's not 0 (meaning an error)
	// if the check for 0 isn't in there, 0 is less than all the other areas which means it would set the invalid area to be the minimum and we don't want that
	if((area2 < min) && (area2 != 0))
	{
		min = area2;

		// we have to reassign the others back to 0 or else they might get written over later and more than one could be classified as the smallest
		*area1_smallest = 0;
		*area2_smallest = 1;
		*area3_smallest = 0;
		*area4_smallest = 0;
	}

	// checks if area3 is less than the current min and it's not 0 (meaning an error)
	if((area3 < min) && (area3 != 0))
	{
		min = area3;

		*area1_smallest = 0;
		*area2_smallest = 0;
		*area3_smallest = 1;
		*area4_smallest = 0;
	}

	// checks if area3 is less than the current min and it's not 0 (meaning an error)
	if((area4 < min) && (area4 != 0))
	{
		min = area4;

		*area1_smallest = 0;
		*area2_smallest = 0;
		*area3_smallest = 0;
		*area4_smallest = 1;
	}

	// if they're all 0, then throw an error to use in the outputs function
	if((area1 == 0) && (area2 == 0) && (area3 == 0) && (area4 == 0))
	{
		*error = 1;
	}


	return;
} 

/*****+***-**-**-*--*-----*-***-----********--******************************
*
*  Function Information
*
*  Name of Function: outputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double area123 // area of triangle containing sides 1, 2, and 3
*    2. double area124 // area of triangle containing sides 1, 2, and 4
*    3. double area134 // area of triangle containing sides 1, 3, and 4
*    4. double area234 // area of triangle containing sides 2, 3, and 4
*    5. double side1 // length of side 1
*    6. double side2 // length of side 2
*    7. double side3 // length of side 3
*    8. double side4 // length of side 4
*    9. int area123_largest // used as boolean, true if area123 is the largest area
*   10. int area124_largest // used as boolean, true if area124 is the largest area
*   11. int area134_largest // used as boolean, true if area134 is the largest area
*   12. int area234_largest // used as boolean, true if area234 is the largest area
*   13. int area123_smallest // used as boolean, true if area123 is the smallest area
*   14. int area124_smallest // used as boolean, true if area124 is the smallest area
*   15. int area134_smallest // used as boolean, true if area134 is the smallest area
*   16. int area234_smallest // used as boolean, true if area234 is the smallest area
*   17. int error // used as boolean, if true prints only the error statement
*    
*
*  Function Description: prints results, areas, side lengths, in the right order given values calculated from other functions and inputted values
*
******+***-**-**-*--*-----*-***-----********--*****************************/
void outputs(double area123, double area124, double area134, double area234, double side1, double side2, double side3, double side4, int area123_largest, int area124_largest, int area134_largest, int area234_largest, int area123_smallest, int area124_smallest, int area134_smallest, int area234_smallest, int error)
{
	// if one or both of largestArea or smallestArea errors out, prints an error message and exits the program
	if(error)
	{
		printf("\nError: No triangles can be given from lengths given!\n");
		return;
	}

	// always prints first line
  printf("\nLargest possible triangle area: ");

	//checks if each is the largest area, then prints the length of it and its corresponding side lengths in order of which they're inputted
	// side note this would have been so much easier if the order of the side lengths in the print statements didn't matter i ended up rewriting the whole program just to fix that because the old one couldn't figure out which area went with which sides
	if(area123_largest)
	{
		printf("%.2f\n", area123);
		printf("Side values used: %.1f, %.1f, %.1f\n", side1, side2, side3);
	}

	if(area124_largest)
	{
		printf("%.2f\n", area124);
		printf("Side values used: %.1f, %.1f, %.1f\n", side1, side2, side4);
	}

	if(area134_largest)
	{
		printf("%.2f\n", area134);
		printf("Side values used: %.1f, %.1f, %.1f\n", side1, side3, side4);
	}

	if(area234_largest)
	{
		printf("%.2f\n", area234);
		printf("Side values used: %.1f, %.1f, %.1f\n", side2, side3, side4);
	}

	// always prints this line
	printf("\nSmallest possible triangle area: ");

	// checks each and sees if it's the smallest, if so prints its area and the side lengths
	if(area123_smallest)
	{
		printf("%.2f\n", area123);
		printf("Side values used: %.1f, %.1f, %.1f\n", side1, side2, side3);
	}

	if(area124_smallest)
	{
		printf("%.2f\n", area124);
		printf("Side values used: %.1f, %.1f, %.1f\n", side1, side2, side4);
	}

	if(area134_smallest)
	{
		printf("%.2f\n", area134);
		printf("Side values used: %.1f, %.1f, %.1f\n", side1, side3, side4);
	}

	if(area234_smallest)
	{
		printf("%.2f\n", area234);
		printf("Side values used: %.1f, %.1f, %.1f\n", side2, side3, side4);
	}

	return;
}