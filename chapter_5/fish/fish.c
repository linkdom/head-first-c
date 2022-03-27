#include <stdio.h>

struct exercise {
    const char *description;
    float duration;
};

struct meal {
    const char *ingredients;
    float weight;
};

struct preferences {
    struct meal food;
    struct exercise exercise;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

struct fish snappy = {"Snappy", "Piranha", 69, 4,
        {
    {"Meat", 0.2},
    {"swim in the jacuzzi", 7.5}
        }
};

void catalog(struct fish fish)
{
    printf("%s is a %s with %i teeth. He is %i\n",
           fish.name, fish.species, fish.teeth, fish.age);
    printf("Snappy likes to eat %s\n", snappy.care.food.ingredients);
    printf("Snappy likes to exercise %f hours\n", snappy.care.exercise.duration);
}

void label(struct fish fish)
{
    printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
           fish.name, fish.species, fish.teeth, fish.age);
    printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n",
           fish.care.food.weight, fish.care.food.ingredients,
           fish.care.exercise.description,fish.care.exercise.duration);
}

int main()
{
    catalog(snappy);
    label(snappy);

    return 0;
}