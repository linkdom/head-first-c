#include <stdio.h>


struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
};

struct fish snappy = {"Snappy", "Piranha", 69, 4};

void catalog(struct fish fish)
{
    printf("%s is a %s with %i teeth. He is %i\n",
           fish.name, fish.species, fish.teeth, fish.age);
}

void label(struct fish fish)
{
    printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
           fish.name, fish.species, fish.teeth, fish.age);
}

int main()
{
    catalog(snappy);
    label(snappy);
    return 0;
}