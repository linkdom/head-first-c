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
	int count = 0;

	if(card[0] >= 3 && card[0] <= 6)
		count++;
	else if(card[0] == 'J', 'Q', 'K')
		count--;
	else if(card == "10")
		count++;

	printf("The count is %i!\n", count);

	return 0;

}
