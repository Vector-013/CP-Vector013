#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;
    }
    vector<vector<ll>> p(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> p[i][j];
        if (v[i] != -1)
        {
            for (int j = 0; j < m; j++)
                p[i][j] = linf;
            p[i][v[i]] = 0;
        }
    }
    vector<vector<ll>> dp(k, vector<ll>(m, linf));
    dp[0] = p[0];

    for (int i = 1; i < n; i++)
    {
        vector<vector<ll>> ndp(k, vector<ll>(m, linf));
        for (int j = 0; j < k; j++)
        {
            for (int z = 0; z < m; z++)
            {
                for (int w = 0; w < m; w++)
                {
                    int q = j + (z != w);

                    if (q < k)
                        ndp[q][w] = min(ndp[q][w], dp[j][z] + p[i][w]);
                }
            }
        }
        dp = ndp;
    }
    ll ans = *min_element(dp[k - 1].begin(), dp[k - 1].end());
    cout << (ans == linf ? -1 : ans) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}