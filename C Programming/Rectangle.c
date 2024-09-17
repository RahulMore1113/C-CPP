#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double width = 32.3;
    double height = 15.3;
    double perimeter = 0.0;
    double area = 0.0;

    perimeter = 2.0 * (height + width);
    area = width * height;

    printf("Width is : %.2f, Heaight is : %.2f, Perimeter is : %.2f", width, height, perimeter);
    printf("\nArea is : %.2f", area);

    return 0;
}