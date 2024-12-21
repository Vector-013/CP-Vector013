#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    vector<string> cap(n);
    for (int i = 0; i < n; i++)
        cin >> cap[i];
    vector<vector<int>> num(n, vector<int>(m));
    vector<vector<ll>> pre(n + 1, vector<ll>(m + 1, 0));
    ll dif = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cap[i][j] == '1')
            {
                num[i][j] = 1;
                dif += a[i][j];
            }
            else
            {
                num[i][j] = -1;
                dif -= a[i][j];
            }
        }
    }
    if (!dif)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + num[i][j];
    }

    ll zgcd = -1;
    for (int i = 0; i + k <= n; i++)
    {
        for (int j = 0; j + k <= m; j++)
        {
            ll cur = pre[i + k][j + k] - pre[i][j + k] - pre[i + k][j] + pre[i][j];
            if (abs(cur) != 0)
            {
                if (zgcd == -1)
                    zgcd = abs(cur);
                else
                    zgcd = __gcd(zgcd, abs(cur));
            }
        }
    }
    if (zgcd == -1)
    {
        cout << "NO\n";
        return;
    }
    cout << (dif % zgcd == 0 ? "YES" : "NO") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}