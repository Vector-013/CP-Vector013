#include <stdio.h>
int main()
{
    long long n;
    scanf("%lld", &n);
    long long pow = 5, ans = 0;
    while (n / pow)
    {
        ans += n / pow;
        pow *= 5;
    }
    printf("%lld", ans);
}