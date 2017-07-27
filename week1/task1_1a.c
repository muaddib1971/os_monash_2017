/* Tutorial 1: Task 1 */

#include <stdio.h>
#include <stdlib.h>
#include "keyboardreader.h"
#include <ctype.h>

#define NAMELEN 40

int main(void)
{
	/* declare two strings: firstname, lastname */
    char fname[NAMELEN + ENDCHARS], lname[NAMELEN + ENDCHARS];
    enum input_result result;
	
	/* prompt for the first name */
    while(result = get_string("Please enter your first name: ", 
        NAMELEN + ENDCHARS, fname), result == FAILURE){

        fprintf(stderr, "Error: line too long. Please try again.\n\n");
    }
	/* prompt for the last name */
    while(result = get_string("Please enter your first name: ", 
        NAMELEN + ENDCHARS, lname), result == FAILURE){

        fprintf(stderr, "Error: line too long. Please try again.\n\n");
    }
	/* print the two initials */
    printf("The two initials are: %c %c\n", 
        toupper(*fname), toupper(*lname));
	return EXIT_SUCCESS;
}
