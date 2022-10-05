#include <stdio.h>
#include <math.h>
int main()
{
    float x1, x2, x3, y1, y2, y3, side1, side2, side3;
    printf("enter coordinates(x1,y1): ");
    scanf("%f%f", &x1, &y1);
    printf("enter coordinates(x2,y2): ");
    scanf("%f%f", &x2, &y2);
    printf("enter coordinates(x3,y3): ");
    scanf("%f%f", &x3, &y3);
    printf("The coordinates are \n (%f,%f)\n (%f,%f)\n (%f,%f)\n", x1, y1, x2, y2, x3, y3);
    // to see if coordinates for a traingle
    side1 = sqrt((pow((x1 - x2), 2)) + (pow((y1 - y2), 2)));

    side2 = sqrt((pow((x2 - x3), 2)) + (pow((y2 - y3), 2)));

    side3 = sqrt((pow((x3 - x1), 2)) + (pow((y3 - y1), 2)));

    float n = sqrt(side1 * side1 + side3 * side3);

    float m = sqrt(side2 * side2 + side3 * side3);

    float o = sqrt(side1 * side1 + side2 * side2);

    if (side1 + side2 > side3 && side1 + side3 > side2 && side3 + side2 > side1)
    {
        printf("The given sides form a triangle\n");
        if (side2 == n || side3 == o || side1 == m)
            printf("The given Triangle is Right Angled Triangle\n");
        if (side1 == side2 && side2 == side3)
            printf("The given Triangle is Equilateral\n");
        if (side1 == side2 || side2 == side3 || side3 == side1)
            printf("The given Triangle is Isosceles\n");

        else
        {
            printf("The given Triangle is Scalene\n");
        }
    }
    else
    {
        printf("The given sides donot form a triangle\n");
    }

    return 0;
}
