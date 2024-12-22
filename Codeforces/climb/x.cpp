//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

using namespace std;

int const N = 1000 + 20;
int n, k, a[N], dp[N], ans;
bool mark[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mark[i][j] = 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            a[j]--;
            for (int l = 0; l < j; l++)
                mark[a[j]][a[l]] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (mark[a[j]][a[i]])
                dp[a[i]] = max(dp[a[i]], dp[a[j]]);
        ans = max(ans, ++dp[a[i]]);
    }

    cout << ans << '\n';
}
