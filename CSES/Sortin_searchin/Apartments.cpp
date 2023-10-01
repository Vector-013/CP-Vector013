#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    std::sort(a, a + n);
    std::sort(b, b + m);
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= k)
        {
            i++;
            j++;
            cnt++;
        }
        else if (a[i] > b[j] + k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    printf("%d", cnt);
}