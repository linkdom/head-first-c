/*
 * A Test area to play with pointers
 */

#include <stdio.h>

int y = 0;

void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    printf("Msg occupies %lu bytes\n", sizeof(*msg));
    //somethings off here and i cant figure out what.
    //sizeof needs a pointer to the message? Even tough the book states otherwise
}

int main () {
    int x = 10;
    printf("x is stored at %p\n", &x);
    printf("y is stored at %p\n", &y);
    char quote[] = "Cookies make you fat";
    printf("The quote string is stored at: %p\n", quote);
    fortune_cookie(quote);
}