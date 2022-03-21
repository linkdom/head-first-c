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

void skip(char *msg)
{
    puts(msg+6);
}

int main () {
    int x = 10;
    printf("x is stored at %p\n", &x);
    printf("y is stored at %p\n", &y);

    char quote[] = "Cookies make you fat";
    printf("Size of the array is: %i\n", sizeof(quote));
    printf("The quote string is stored at: %p\n", quote);
    fortune_cookie(quote);

    char *msg_from_amy = "Don't call me"; //this is a constant (hence read-only)
    skip(msg_from_amy);

    int nums[] = {1,2,3};
    printf("nums is at %p\n", nums);
    printf("nums + 1 is at %p\n", nums + 1);
    //this tells us that an int is 4 bytes long

    char test[] = "test";
    printf("test is at %p\n", test);
    printf("test + 1 is at %p\n", test + 1);
    //and this tells us that a char is 1 byte long
}