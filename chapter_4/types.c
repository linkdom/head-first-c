#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
//    int x = 7;
//    int y = 2;
//    //float z = (float)x/(float)y; // is the same as
//    float z = (float)x/y;
//    printf("z = %f\n", z);

    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %zu bytes\n", sizeof(int));
    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
    printf("A float takes %zu bytes\n", sizeof(float));

    return 0;
}