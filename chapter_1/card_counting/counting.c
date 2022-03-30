/*
 * A program that implements the practice
 * of card counting
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
	char card[3];
    int count = 0;
    int execute = 1;

    do {
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
                break;
            case 'X':
                execute = 0;
            default:
                if(val <= 10)
                    val = atoi(card);
                else
                    puts("Invalid card");

        }


        if(val >= 3 && val <= 6) {
            puts("Count has gone up");
            count++;
        }
        else if(val == 10) {
            puts("Count has gone down");
            count--;
        }

        printf("Current count is: %i\n", count);

    } while (execute);
    return 0;





}
