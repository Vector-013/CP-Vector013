#include <stdio.h>
#include <stdlib.h>
int numofsubarrays(int a[], int n, int key, int k)
{
    int cnt = 0, i = 0, sum = 0;
    while (i < n)
    {
        sum += a[i];
        if (sum >= key)
        {
            cnt++;
            sum = 0;
        }
        i++;
    }
    if (sum == 0)
        return cnt;
    else if (sum < key && cnt <= k)
        return k - 1;
    else
        return cnt;
}
int main()
{
    int n, k, sum = 0, ans, mid, s, e;
    printf("enter n, k, array\n");
    scanf("%d %d", &n, &k);
    k++;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    s = 0;
    e = sum;
    int stop = 0;
    while (s <= e)
    {
        stop++;
        if (stop == 10)
            break;
        mid = (s + e + 1) / 2;
        printf("s=%d mid=%d end=%d\n", s, mid, e);
        if (s == e)
            break;
        if (numofsubarrays(a, n, mid, k) < k)
            e = mid - 1;
        else
            s = mid;
    }
    printf("%d\n", mid);
}
