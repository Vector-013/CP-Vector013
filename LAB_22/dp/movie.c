#include <stdlib.h>
#include <stdio.h>
int gb15(int dp[], int q[], int w[], int n, int d)
{
    if (d > n)
        return 0;
    if (dp[d] != -1)
        return dp[d];
    int pos = (gb15(dp, q, w, n, d + 1) + q[d]);
    int chk = (gb15(dp, q, w, n, d + 2) + w[d + 1]);
    int ret = (pos > chk) ? pos : chk;
    dp[d] = ret;
    return ret;
}
int main()
{
    int n;
    printf("Enter the number of days: ");
    scanf("%d", &n);
    int q[n + 1], w[n + 2];
    printf("Enter the download size restrictions of the first website (in GB): ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &q[i]);
    printf("Enter the download size restrictions of the second website (in GB): ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    q[0] = 0;
    w[0] = 0;
    w[n + 1] = 0;
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    int ans = gb15(dp, q, w, n, 0);
    printf("and....%d", ans);
}