/* Tutorial 1: Task 5 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 3

int main(void)
{
    int count;
    /* declare an integer array of size 3 */
    int nums[MAX_NUMS];
    /* initialise random number generator */
    srand(time(NULL));	
    /* generate three random numbers */
    for(count = 0; count < MAX_NUMS; ++count){
        nums[count] = rand();
    }
    /* output the three random numbers */
    printf("The three random numbers are: ");
    for(count = 0; count< MAX_NUMS; ++count){
        printf("%d\t", nums[count]);
    }
    putchar('\n');
    return EXIT_SUCCESS;
}
