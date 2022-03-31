/*
 * Linked Lists
 *
 * The code in this file declares a new variable, skill, right in the middle of the code.
 * This is allowed only in C99 and C11. In ANSI C, you need to declare your local variables
 * at the top of a function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island{
    char *name;
    char *opens;
    char *closes;
    struct island *next; //This is the pointer to the next island which is needed in a linked list.
} island;

island* create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;

    return i; //The function returns the address of the new struct.
}

void display(island *start)
{
    island *i = start;

    for(; i != NULL; i = i->next) {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}

int main() {
    island amity = {"Amity", "09:00", "17.00", NULL};
    island craggy = {"Craggy", "09:00", "17.00", NULL};
    island isla = {"Isla Nublar", "09:00", "17.00", NULL};
    island shutter = {"Shutter", "09:00", "17.00", NULL};

    amity.next = &craggy;
    craggy.next = &isla;
    isla.next = &shutter;

    island skull = {"Skull", "09:00", "17:00", NULL};
    isla.next = &skull;
    skull.next = &shutter;
    display(&amity);

    char name[80];
    fgets(name, 80, stdin);
    //char *copy = strdup(name);
    //This needs to be done because the name string just records
    //where the name string lives in memory. So we need to make
    //a copy because otherwise it would be overwritten by the second input
    //Nevermind, it is better to call it inside the create function
    //on the name field because the opens and closes fields are put
    //in the read only memory because they are string literals (constants)
    //and so we know that they never change and can immediately call the strup().
    island *p_island0 = create(name);
    display(p_island0);

    fgets(name, 80, stdin);
    island *p_island1 = create(name);
    p_island0->next = p_island1;
    display(p_island0);
}