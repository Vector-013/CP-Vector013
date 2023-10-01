#include <stdio.h>
#include <stdlib.h>
int c, n;
int knapsack(int dp[c + 1][n + 1], int i, int j, int wt[], int p[])
{
    if (dp[i][j] != -1)
        return dp[i][j];
    // j means upto j itmes are in consideration. add jth or not is our call. if add j , go to call with i-wt[i],j-1
    // or call i,j-1 if not added jth item
    int curr = knapsack(dp, i, j - 1, wt, p);
    if (i >= 0 && j >= 0 && i >= wt[j - 1])
    {
        if ((knapsack(dp, i - wt[j - 1], j - 1, wt, p) + p[j - 1]) > curr)
        {
            curr = (knapsack(dp, i - wt[j - 1], j - 1, wt, p) + p[j - 1]);
        }
    }
    dp[i][j] = curr;
    return curr;
}
void getitems(int dp[c + 1][n + 1], int i, int j, int wt[], int p[])
{
    while (i >= 0 && j >= 0 && i >= wt[j - 1])
    {
        if (dp[i][j] > dp[i][j - 1])
        {
            printf("%d ", wt[j - 1]);
            i -= wt[j - 1];
        }
        j--;
    }
}

int main()
{
    printf("enter no of items and capacity : ");
    scanf("%d%d", &n, &c);
    int wt[n], p[n];
    printf("input of wts and prices corresponding :\nweight price\n");
    for (int i = 0; i < n; i++)
        scanf("%d%d", &wt[i], &p[i]);
    int dp[c + 1][n + 1];
    for (int i = 0; i <= c; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= c; i++)
        dp[i][0] = 0;
    int ans = knapsack(dp, c, n, wt, p);
    printf("\n%d\n\n", ans);
    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= n; j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    printf("\n");
    getitems(dp, c, n, wt, p);
}