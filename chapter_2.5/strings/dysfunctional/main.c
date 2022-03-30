#include <stdio.h>
#include <string.h>

int main ()
{
    char string0[] = "dysfunctional";
    char string1[] = "fun";

    if(strstr(string0, string1)) {
        puts("I found the fun in dysfunctional!");
    }
}