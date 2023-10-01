#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long n;
    scanf("%lld", &n);
    if (n % 4 == 1 || n % 4 == 2)
    {
        printf("NO\n");
        return 0;
    }
    else if (n % 4)
    {

        {
            printf("YES\n");
            printf("%lld\n%lld ", n / 2, n);
            long long pos = 1;
            while (pos <= n / 4)
            {
                printf("%lld %lld ", pos, n - pos);
                pos++;
            }
            printf("\n%lld\n", n / 2 + 1);
            while (pos <= n / 2)
            {
                printf("%lld %lld ", pos, n - pos);
                pos++;
            }
        }
    }
    else
    {
        printf("YES\n");
        printf("%lld\n", n / 2);
        long long pos = 1;
        while (pos <= n / 4)
        {
            printf("%lld %lld ", pos, n + 1 - pos);
            pos++;
        }
        printf("\n%lld\n", n / 2);
        while (pos <= n / 2)
        {
            printf("%lld %lld ", pos, n + 1 - pos);
            pos++;
        }
    }
}