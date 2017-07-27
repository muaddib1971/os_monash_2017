/* Tutorial 1: Task 3 */

#include <stdio.h>
#include <stdlib.h>
#include "keyboardreader.h"

/* function prototypes */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main(void)
{
	/* declare two integers */
	int number1;
	int number2;
    enum input_result res;

	/* prompt for the first integer */
    while(res = get_int("Please enter the first number: ", &number1), 
        res == FAILURE){
        fprintf(stderr, "Error: invalid input. Please try again.\n\n");
    }
	
	/* prompt for the second integer */
    while(res = get_int("Please enter the second number: ", &number2), 
        res == FAILURE){
        fprintf(stderr, "Error: invalid input. Please try again.\n\n");
    }
	/* invoke each of the four functions */
    printf("The result of addition is: %d\n", add(number1, number2));
    printf("The result of subtraction is: %d\n", 
        subtract(number1, number2));
    printf("The result of division is: %d\n", divide(number1, number2));
    printf("The result of multiplication is: %d\n", 
        multiply(number1, number2));
	return EXIT_SUCCESS;
}

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a/b;
}
