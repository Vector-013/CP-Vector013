#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int mini(int a, int b)
{
    int ret = a < b ? a : b;
    return ret;
}
int jumper(int s, int n, int k, int h[], int dp[])
{
    if (s > n)
        return 1e4 + 5;
    if (s == n)
        return 0;
    if (dp[s - 1] != -1)
        return dp[s - 1];
    if (s == n - 1)
        return abs(h[n - 1] - h[n - 2]);
    int ret;
    int cur = jumper(s + 1, n, k, h, dp) + abs(h[s - 1] - h[s]);
    for (int i = 2; i <= k; i++)
    {
        cur = mini(cur, (jumper(s + i, n, k, h, dp) + abs(h[s - 1] - h[s - 1 + i])));
    }
    dp[s - 1] = cur;
    return cur;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int h[n + k];
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
    for (int i = n; i < n + k; i++)
        h[i] = 1e4 + 10;
    int dp[n];

    for (int i = 0; i < n; i++)
        dp[i] = -1;
    int ans = jumper(1, n, k, h, dp);
    printf("%d\n", ans);
}