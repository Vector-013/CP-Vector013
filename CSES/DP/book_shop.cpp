#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> h(n + 1), s(n + 1);
    h[0] = 0, s[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    vector<vector<int>> dp(x + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= x; i++)
        dp[i][0] = 0;

    int a, b;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a = dp[i][j - 1];
            if (i >= h[j])
            {
                b = dp[i - h[j]][j - 1];
                dp[i][j] = max(a, b + s[j]);
            }
            else
                dp[i][j] = a;
        }
    }

    cout << dp[x][n];
}