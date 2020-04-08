#include <stdio.h>

void swap( int *a, int *b )
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Cases( int a, int b, int c )
{
    if (a >= b && a >= c)
    {
        swap(&a, &c);
        if (a >= b)
            swap(&a, &b);
    }
    else if (b >= a && b >= c)
    {
        swap(&b, &c);
        if (a >= b)
            swap(&a, &b);
    }
    else if (a >= b)
        swap(&a, &b);

    for (; a != b; a++, c--);
    for (; a != c && a != c + 1 && a != c - 1; a++, b++, c -= 2);
    printf("a: %i\nb: %i\nc: %i\n", a, b, c);
}

int main( void )
{
    int a, b, c;

    printf("a:");
    scanf("%i", &a);
    printf("b:");
    scanf("%i", &b);
    printf("c:");
    scanf("%i", &c);
    Cases(a, b, c);
    return 0;
}
