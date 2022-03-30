#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
    size_t len = strlen(s);

    char *t = s + len - 1;

    while(t >= s) {
        printf("%c", *t);

        t = t - 1;
    }
    puts("");
}

int main()
{
    char *names_for_dog[] = {"Bowser", "Bonza", "Snodgrass"};
    print_reverse(*names_for_dog);
}