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

struct Matrix {
    long long arr[2][2];
};

struct Matrix mult_matrix( struct Matrix* left, struct Matrix* right )
{
    struct Matrix rs;
    rs.arr[0][0] = left->arr[0][0] * right->arr[0][0] + left->arr[0][1] * right->arr[1][0];
    rs.arr[0][1] = left->arr[0][0] * right->arr[0][1] + left->arr[0][1] * right->arr[1][1];

    rs.arr[1][0] = left->arr[1][0] * right->arr[0][0] + left->arr[1][1] * right->arr[1][0];
    rs.arr[1][1] = left->arr[1][0] * right->arr[0][1] + left->arr[1][1] * right->arr[1][1];
    return rs;
}

struct Matrix getDiagonalMatrix( void )
{
    struct Matrix res;
    res.arr[0][0] = 1;
    res.arr[0][1] = 0;
    res.arr[1][0] = 0;
    res.arr[1][1] = 1;
    return res;
}

struct Matrix getFibBaseMatrix( void )
{
    struct Matrix res;
    res.arr[0][0] = 1;
    res.arr[0][1] = 1;
    res.arr[1][0] = 1;
    res.arr[1][1] = 0;
    return res;
}

struct Matrix pow_matrix( struct Matrix* m, int pow )
{
    struct Matrix res = getDiagonalMatrix();
    for (int i = 0; i < pow; i++)
    {
        res = mult_matrix(&res, m);
    }
    return res;
}

struct Matrix pow_matrix_quick( struct Matrix* m, int pow )
{
    struct Matrix base = *m;
    struct Matrix res = getDiagonalMatrix();
    while (pow > 0)
    {
        while (pow % 2 == 0)
        {
            base = mult_matrix(&base, &base);
            pow /= 2;
        }
        res = mult_matrix(&res, &base);
        pow--;
    }
    return res;
}

long long fib( int n )
{
    struct Matrix base = getFibBaseMatrix();
    struct Matrix res = pow_matrix_quick(&base, n);
    return res.arr[0][0];
}

long long fib_slow( int n )
{
    if (n <= 1) return 1;
    return fib_slow(n - 1) + fib_slow(n - 2);
}

int main( void )
{
    int x;

    scanf("%i", &x);

    for (int i = 0; i <= x; i++)
        printf("%d %lli\n", i, fib(i));

    return 0;
}
