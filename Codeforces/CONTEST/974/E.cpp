#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    ll n, m, h;
    cin >> n >> m >> h;
    vector<bool> hrs(n, false);
    vector<vector<pair<ll, ll>>> g(n);
    int a, b, w;
    for (int i = 0; i < h; i++)
    {
        cin >> a;
        a--;
        hrs[a] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b>>w;
        a--;
        b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    auto djikstra = [&](ll s)
    {
        vector<ll> d(2 * n, linf);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.emplace(0ll, 2 * s);

        while (!pq.empty())
        {
            auto [l, u] = pq.top();
            pq.pop();

            if (d[u] != linf)
                continue;

            d[u] = l;
            int hh = u % 2;
            int v = u / 2;

            if (!hh && hrs[v])
            {
                pq.emplace(l, 2 * v + 1);
            }
            for (auto [x, y] : g[v])
            {
                pq.emplace(l + (hh ? y / 2 : y), 2 * x + hh);
            }
        }
        vector<ll> z(n, inf);
        for (int i = 0; i < n; i++)
        {
            z[i] = min(d[2 * i], d[2 * i + 1]);
        }
        return z;
    };

    auto v1 = djikstra(0ll);
    auto vn = djikstra(n - 1);
    ll ans = linf;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, max(v1[i], vn[i]));
    }
    if (ans == linf)
    {
        ans = -1;
    }
    cout << ans << '\n';
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