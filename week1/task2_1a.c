/* Tutorial 1: Task 2 */

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "keyboardreader.h"
int main(void)
{
	/* declare three variables */
    enum input_result res;
    double radius, circ, area;
	
	/* prompt for the radius */
    while(res = get_double("Please enter the radius for the circle: ", 
        &radius), res == FAILURE){
        fprintf(stderr, "Error: line entered was too long. \n"
            "Please try again.\n\n");
    }
    if(res == EOB){
        return EXIT_SUCCESS;
    }

	/* compute and output the area */

    area = M_PI * radius * radius;
    printf("The area is %f\n", area);
	
	/* compute and output the circumference */
	circ = 2 * M_PI * radius;
    printf("The circumference is %f\n", circ);
	return EXIT_SUCCESS;
}
