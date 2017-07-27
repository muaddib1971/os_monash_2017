/* Tutorial 1: Task 4 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "keyboardreader.h"
enum{
    MIN_NUM=100, MAX_NUM=999
};

enum position{
    BEGIN=3,MIDDLE=2,END=1
};
#define MAX_DIGIT 3

int reverse_num(int,int);

int main(void)
{
	/* declare the variables needed */
    int num, reversed;
    enum input_result result;
    bool success = false;

	/* prompt for a 3-digit number */
    while(!success){
        result = get_int("Please enter a 3 digit number: ", &num);
        if(result == FAILURE){
            fprintf(stderr, "Error: invalid input. Please try again.\n\n");
            continue;
        }
        if(num < MIN_NUM || num > MAX_NUM){
            fprintf(stderr, "Error: %d is outside the allowed range.\n\n",
                num);
        }
        success=true;
    }

	/* produce the reverse order */
    reversed = reverse_num(num, MAX_DIGIT);
	
    /* output the 3-digit number in reverse order */
    printf("the reversed number is: %d\n", reversed); 
	
	return EXIT_SUCCESS;
}


int reverse_num(int num ,int digit_num)
{
    int reversed;
    int remainder;
    if(digit_num <= 0)
    {
        return 0;
    }
    
    remainder = num % (int)pow(10, digit_num-1);
    num -= remainder;
    switch(digit_num)
    {
        case BEGIN:
            num /= 100;
            break;
        case MIDDLE:
            break;
        case END:
            num *= 100;
    }
    -- digit_num;
    reversed = num + reverse_num(remainder, digit_num);
    return reversed;
}
