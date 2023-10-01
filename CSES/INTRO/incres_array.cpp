#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long n;
    scanf("%lld", &n);
    long long a[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    long long cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            cnt += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    printf("%lld", cnt);
}