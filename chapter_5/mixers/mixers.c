/*
 * It's Margarita Night at the Head First Lounge, but after one too many samples, it looks like the
 * guys have mixed up their recipes. See if you can find the matching code fragments for the different
 * margarita mixes.
 */
#include <stdio.h>

typedef union {
    float lemon;
    int lime_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
} margarita;

int main()
{
//    margarita m = {2.0, 1.0, {2}};
//    printf("%2.1f measures of tequila\n"
//           "%2.1f measures of cointreau\n"
//           "%2.1f measures of juice\n",
//           m.tequila,
//           m.cointreau,
//           m.citrus.lemon);

//    margarita m = {2.0, 1.0, {0.5}};
//    printf("%2.1f measures of tequila\n"
//           "%2.1f measures of cointreau\n"
//           "%2.1f measures of juice\n",
//           m.tequila,
//           m.cointreau,
//           m.citrus.lemon);
//
    margarita m = {2.0,1.0,{.lime_pieces=1}};
    printf("%2.1f measures of tequila\n"
           "%2.1f measures of cointreau\n"
           "%i pieces of lime\n",
           m.tequila,
           m.cointreau,
           m.citrus.lime_pieces);
}