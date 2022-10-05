#include <stdio.h>

int main()
{
    int y;
    // Reading 1st Polynomial
    int terms1, i, j;
    printf("Enter number of terms: ");
    scanf("%d", &terms1);
    int power1[terms1], coeff1[terms1];
    for (int i = 0; i < terms1; i++)
    {
        printf("Enter the power of term %d : ", i + 1);
        scanf("%d", &power1[i]);
        printf("Enter the coefficient of x^(%d) : ", power1[i]);
        scanf("%d", &coeff1[i]);
    }

    // Reading 2nd polynomial

    int terms2;
    printf("Enter number of terms: ");
    scanf("%d", &terms2);
    int power2[terms2], coeff2[terms2];
    for (int i = 0; i < terms2; i++)
    {
        printf("Enter the power of term %d : ", i + 1);
        scanf("%d", &power2[i]);
        printf("Enter the coefficient of x^(%d) : ", power2[i]);
        scanf("%d", &coeff2[i]);
    }

    y = terms1 + terms2;
    // Calculating the sum
    int k = 0;
    int rescoeff[y], respower[y];
    for (int i = 0; i < terms1; i++)
    {
        for (int j = 0; j < terms2; j++)
        {
            if (power1[i] == power2[j])
            {
                printf(" %dx^(%d) ", (coeff1[i] + coeff2[j]), power1[i]);
                coeff1[i] = coeff2[j] = 0;
                printf("+");
            }
        }
    }
    int m = 0, n = 0;
    for (int i = 0; i < terms1; i++)
    {
        if (coeff1[i] != 0)
        {
            m++;
        }
    }

    for (int i = 0; i < terms1; i++)
    {
        if (coeff1[i] != 0)
        {
            printf(" %dx^(%d) ", coeff1[i], power1[i]);
            n++;
            printf("+");
            if (n == m)
                break;
        }
    }

    int p = 0, q = 0;
    for (int i = 0; i < terms1; i++)
    {
        if (coeff1[i] != 0)
        {
            p++;
        }
    }

    for (int j = 0; j < terms2; j++)
    {
        if (coeff2[j] != 0)
        {
            printf(" %dx^(%d) ", coeff2[j], power2[j]);
            q++;
            if (p == q)
                break;
            printf("+");
        }
    }
    return 0;
}