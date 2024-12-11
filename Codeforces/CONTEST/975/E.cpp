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
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    int n, a, b;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[b].push_back(a);
        g[a].push_back(b);
    }

    vector<int> ans(n, 0), d(n, 0), msd(n, 0);
    auto dfs = [&](auto &self, int u, int p) -> void
    {
        msd[u] = d[u];
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            d[v] = d[u] + 1;
            self(self, v, u);
            msd[u] = max(msd[u], msd[v]);
        }

        ans[d[u]]++;
        if (msd[u] + 1 < n)
            ans[msd[u] + 1]--;
    };

    dfs(dfs, 0, -1);
    for (int i = 1; i < n; i++)
        ans[i] += ans[i - 1];
    int req = *max_element(ans.begin(), ans.end());
    cout << n - req << '\n';
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