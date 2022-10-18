//program to find pass or fail
#include <stdio.h>
int main()
{
    int physics, chemistry, maths;
    float total;
    printf("Enter the marks of physics = ");
    scanf("%5d", &physics);
    printf("Enter the marks of chemistry = ");
    scanf("%5d", &chemistry);
    printf("Enter the marks of maths = ");
    scanf("%5d", &maths);
    total = (physics + chemistry + maths) / 3;
    if ((total < 40) || physics < 33 || maths < 33 || chemistry < 33)
    {
        printf("Your total percent is %f and you are fail\n", total);
    }
    else
        printf("Your total percent is %f and you are pass \n", total);
    return 0;
}