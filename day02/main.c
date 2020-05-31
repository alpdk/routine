#include <stdio.h>

long long quick_power( int base, int pow )
{
    long long res = 1;

    while (pow > 0)
    {
        while (pow % 2 == 0)
        {
            base = base * base;
            pow /= 2;
        }
        res *= base;
        pow--;
    }
    return res;
}

int main( void )
{
    int x, y;

    printf("Print x^y!\nX:");
    scanf("%i", &x);
    printf("Y:");
    scanf("%i", &y);
    printf("%i^%i = %lli", x, y, quick_power(x, y));
}
