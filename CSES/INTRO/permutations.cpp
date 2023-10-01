#include <stdio.h>
int main()
{
    long long n;
    scanf("%lld", &n);
    if (n == 2 || n == 3)
    {
        printf("NO SOLUTION");
        return 0;
    }
    printf("%lld ", n / 2 + 1);
    for (long long i = 1; i < n / 2; i++)
    {
        printf("%lld %lld ", i, n + 1 - i);
    }
    if (!(n & 1))
        printf("%lld", n / 2);
    else
        printf("%lld %lld ", n / 2, n + 1 - n / 2);
}