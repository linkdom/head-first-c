/*
 * A program that implements the practice
 * of card counting
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
	char card[3];
	puts("Please enter a card: ");
	scanf("%s", card);
    int val = 0;

    switch(card[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
        default:
            val = atoi(card);
    }

    printf("The card value is: %i\n", val);

	if(val >= 3 && val <= 6) {
        puts("Count has gone up");
    }
	else if(val == 10) {
        puts("Count has gone down");
    }

	return 0;

}
