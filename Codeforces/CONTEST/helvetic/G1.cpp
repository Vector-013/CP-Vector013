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
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
ll min(ll a, ll b)
{
    if (a <= b)
        return a;
    else
        return b;
}
void solve()
{
    ll n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = linf;

    auto chk = [&](auto &self, int u, int p) -> ll // find size of kids and cmpr
    {
        ll uv = 1;
        for (auto v : g[u])
        {
            if (v != p)
            {
                ll nv = self(self, v, u);
                ans = min(ans, nv * nv * 1ll + (n - nv) * (n - nv) * 1ll);
                uv += nv;
            }
        }
        return uv;
    };
    ll x = chk(chk, 0, -1);
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