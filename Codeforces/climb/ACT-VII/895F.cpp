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

    vector<int> a(n), c(n), deg(n), ans, vis(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        deg[a[i]]++;
    }
    for (auto &x : c)
        cin >> x;

    auto dfs = [&](auto self, int x) -> void
    {
        ans.push_back(x);
        vis[x] = true;
        if (--deg[a[x]] == 0)
        {
            self(self, a[x]);
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 0 && !vis[i])
            dfs(dfs, i);
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vector<int> b, ca;
        for (int j = i; !vis[j]; j = a[j])
        {
            vis[j] = true;
            b.push_back(j);
            ca.push_back(c[j]);
        }
        int p = min_element(ca.begin(), ca.end()) - ca.begin();
        for (int j = 0; j < b.size(); j++)
        {
            ans.push_back(b[(j + 1 + p) % b.size()]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " \n"[i == n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
