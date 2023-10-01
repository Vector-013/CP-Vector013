#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long x, y, ans;
        scanf("%lld %lld", &x, &y);
        if (y > x)
        {
            if (y & 1)
                ans = y * y - x + 1;
            else
                ans = (y - 1) * (y - 1) + x;
        }
        else
        {
            if (x & 1)
                ans = (x - 1) * (x - 1) + y;
            else
                ans = x * x - y + 1;
        }
        printf("%lld\n", ans);
    }
}