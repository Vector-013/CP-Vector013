#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    vector<int> ans(sum + 1, false);
    vector<vector<int>> dp((sum + 1), vector<int>(n + 1, 0));

    dp[v[1]][1] = 1;
    ans[v[1]] = 1;

    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= sum; i++)
        {
            dp[v[j]][j] = 1;
            ans[v[j]] = 1;
            if (i > v[j] && dp[i - v[j]][j - 1])
            {
                dp[i][j] = 1;
                ans[i] = 1;
            }
            if (dp[i][j - 1])
                dp[i][j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= sum; i++)
        cnt += dp[i][n];

    cout << cnt << '\n';
    for (int i = 1; i <= sum; i++)
        if (ans[i])
            cout << i << " ";
    cout << '\n';
}