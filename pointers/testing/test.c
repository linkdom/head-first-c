/*
 * A Test area to play with pointers
 */

#include <stdio.h>

int y = 0;

void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    printf("Msg occupies %i bytes\n", sizeof(msg));
}

int main () {
    int x = 10;
    printf("x is stored at %p\n", &x);
    printf("y is stored at %p\n", &y);
    char quote[] = "Cookies make you fat";
    printf("Size of the array is: %i\n", sizeof(quote));
    printf("The quote string is stored at: %p\n", quote);
    fortune_cookie(quote);
}