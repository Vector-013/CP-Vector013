#include <stdio.h>
int main()
{
    long long n;
    scanf("%lld", &n);
    long long ans = 1, mod = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * 2;
        ans = ans % mod;
    }
    printf("%lld", ans);
}