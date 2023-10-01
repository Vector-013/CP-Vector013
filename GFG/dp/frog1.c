#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int jumper(int s, int n, int h[], int dp[])
{
    if (dp[s - 1] != -1)
        return dp[s - 1];
    if (s >= n)
        return 0;
    if (s == n - 1)
        return abs(h[n - 1] - h[n - 2]);
    int cur = jumper(s + 1, n, h, dp) + abs(h[s - 1] - h[s]);
    int pol = jumper(s + 2, n, h, dp) + abs(h[s - 1] - h[s + 1]);
    int ret = cur < pol ? cur : pol;
    dp[s - 1] = ret;
    return ret;
}
int main()
{
    int n;
    scanf("%d", &n);
    int h[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = -1;
    int ans = jumper(1, n, h, dp);
    printf("%d\n", ans);
}