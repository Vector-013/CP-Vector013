#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const ll mod = 1e9 + 7;
#define pb push_back
#define pp pop_back
#define f(i, n) for (int i = 0; i < n; i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, i, j, len, cnt, dis = 1;
    cin >> n;
    int a[n], b[n];

    f(i, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    f(i, n - 1)
    {
        if (b[i] != b[i + 1])
            dis++;
    }
    int d[dis];
    j = 0;
    f(i, n - 1)
    {
        if (b[i] != b[i + 1])
            d[j++] = b[i];
    }
    if (j != dis)
        d[j] = b[n - 1];
    int dp[n + 1][dis + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= dis; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= dis; j++)
        {
            if (a[i - 1] == d[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    len = dp[n][dis];
    cout << len << '\n';
    // int ans[len];
    // cnt = len - 1;
    // i = n;
    // j = dis;
    // while (i > 0 && j > 0)
    // {
    //     if (a[i - 1] == d[j - 1])
    //     {
    //         ans[cnt--] = a[i - 1];
    //         i--;
    //         j--;
    //     }
    //     else if (dp[i - 1][j] >= dp[i][j - 1])
    //         i--;
    //     else
    //         j--;
    // }
    // f(i, len)
    // {
    //     cout << ans[i] << " ";
    // }
}