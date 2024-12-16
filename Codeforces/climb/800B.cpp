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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> lr(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    for (auto &i : lr)
        cin >> i.first >> i.second;
    ll ans = 0;
    auto dfs = [&](auto self, int u) -> ll
    {
        ll z = 0, x = 0;
        for (auto v : g[u])
            z += self(self, v);

        if (z >= lr[u].first)
            x = min(z, (ll)lr[u].second);
        else
        {
            x = lr[u].second;
            ans++;
        }
        return x;
    };
    dfs(dfs, 0);
    cout << ans << "\n";
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