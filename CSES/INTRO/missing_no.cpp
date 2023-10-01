#include <stdio.h>
int main()
{
    long long n, sum = 0, a;
    scanf("%lld", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%lld", &a);
        sum += a;
    }
    printf("%ld", ((n * (n + 1)) / 2) - sum);
}