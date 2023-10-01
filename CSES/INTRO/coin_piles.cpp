#include <stdio.h>
int main()
{
    long long t, n, a, b;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &a, &b);
        if ((a + b) % 3 == 0 && (2 * a - b) % 3 == 0 && (2 * b - a) % 3 == 0 && 2 * a - b >= 0 && 2 * b - a >= 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}