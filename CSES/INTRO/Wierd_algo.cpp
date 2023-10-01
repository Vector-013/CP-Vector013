#include <stdio.h>
int main()
{
    long long n;
    scanf("%ld", &n);
    printf("%ld ", n);
    while (n != 1)
    {
        if (n & 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        printf("%ld ", n);
    }
}