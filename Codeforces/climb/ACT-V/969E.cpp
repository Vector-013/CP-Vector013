#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n;
    ll w;
    std::cin >> n >> w;

    std::vector<int> q(n);
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; i++)
    {
        std::cin >> q[i];
        q[i]--;
        g[q[i]].push_back(i);
    }

    int cur = 0;

    std::vector<std::vector<int>> f(n);
    std::vector<int> cnt(n);
    std::vector<i64> dis(n);
    auto dfs = [&](auto &&self, int x) -> void
    {
        cur++;
        for (auto y : g[x])
        {
            f[y].push_back(cur - 1);
            cnt[cur - 1]++;
            self(self, y);
            f[y].push_back(cur - 1);
            cnt[cur - 1]++;
        }
    };
    dfs(dfs, 0);

    ll sum = 0;
    int tot = n;
    for (int i = 1; i < n; i++)
    {
        int x;
        ll y;
        std::cin >> x >> y;
        x--;
        for (auto j : f[x])
        {
            cnt[j]--;
            dis[j] += y;
            if (cnt[j] == 0)
            {
                tot--;
            }
        }
        sum += y;
        std::cout << w * tot + sum * (2 - tot) << " \n"[i == n - 1];
    }
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