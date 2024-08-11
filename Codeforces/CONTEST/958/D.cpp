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
void update_tree(vector<vector<ll>> &g, vector<vector<ll>> &dp, vector<ll> &z, ll &n, ll p, ll v, ll last, ll &h, ll &cnt);

void dfs(vector<vector<ll>> &g, vector<vector<ll>> &dp, vector<ll> &z, ll &n, ll p, ll v, ll &h, ll &cnt)
{
    if (v != 0 && g[v].size() == 1)
    {
        // cout << "here\n";
        h += z[v];
        dp[v][0] = 0;
        dp[v][1] = z[v];
        return;
    }
    for (auto u : g[v])
    {
        if (u != p)
        {
            dfs(g, dp, z, n, v, u, h, cnt);
            dp[v][1] += dp[u][0];
            dp[v][0] += max(dp[u][1], dp[u][0]);
        }
    }
    dp[v][1] += z[v];
    h += z[v];

    if (v == 0)
    {
        for (auto u : g[v])
        {
            if (u != p)
            {
                if (dp[v][0] >= dp[v][1])
                {
                    update_tree(g, dp, z, n, v, u, 0, h, cnt);
                }
                else
                {
                    if (z[v] != 0)
                        cnt++;
                    z[v] = 0;
                    update_tree(g, dp, z, n, v, u, 1, h, cnt);
                }
            }
        }
    }
    return;
}
void update_tree(vector<vector<ll>> &g, vector<vector<ll>> &dp, vector<ll> &z, ll &n, ll p, ll v, ll last, ll &h, ll &cnt)
{
    if (g[v].size() == 1)
    {
        if (last == 1)
            return;
        else
        {
            if (z[v] != 0)
                cnt++;
            z[v] = 0;
            return;
        }
    }
    for (auto u : g[v])
    {
        if (u != p)
        {
            if (last)
            {
                update_tree(g, dp, z, n, v, u, 0, h, cnt);
            }
            else
            {
                if (dp[v][0] >= dp[v][1])
                {
                    update_tree(g, dp, z, n, v, u, 0, h, cnt);
                }
                else
                {
                    if (z[v] != 0)
                        cnt++;
                    z[v] = 0;
                    update_tree(g, dp, z, n, v, u, 1, h, cnt);
                }
            }
        }
    }
}

void iter(vector<vector<ll>> &g, vector<vector<ll>> &dp, vector<ll> &z, ll &n, ll &h, ll &cnt)
{
    while (cnt < n)
    {
        // cout << "cnt " << cnt << '\n';
        dfs(g, dp, z, n, -1ll, 0ll, h, cnt);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << i << " " << dp[i][0] << " " << dp[i][1] << '\n';
        // }
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
    }
}

void solve()
{
    ll n;
    ll h = 0;
    ll cnt = 0;
    cin >> n;
    vector<ll> z(n);
    for (int i = 0; i < n; i++)
        cin >> z[i];
    vector<vector<ll>> g(n);
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    ll a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    if (n == 1)
    {
        cout << z[0] << '\n';
        return;
    }
    iter(g, dp, z, n, h, cnt);
    cout << h << '\n';
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

// 1
// 20
// 664556874599 846277712973 202583660369 607003345225 105485133997 834530794696 785507635247 776507803963 969228522630 414633140433 554185670830 766104946151 83491693442 443632762559 522910401684 880748492912 939193291329 62812828957 489943526655 272896080233
// 19 7
// 13 7
// 16 19
// 5 13
// 12 13
// 6 7
// 20 7
// 15 16
// 18 16
// 9 15
// 3 16
// 2 9
// 1 18
// 17 18
// 14 18
// 4 2
// 8 15
// 10 7
// 11 14