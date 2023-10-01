#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    std::sort(a, a + n);
    int i = 0, j = n - 1, pair = 0;
    while (i < j)
    {
        while (i < j && a[i] + a[j] > x)
            j--;
        if (i >= j)
            break;
        pair++;
        i++;
        j--;
    }
    printf("%d", n - pair);
}