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

int dfs(vector<vector<int>> &g, int n, vector<int> &a, int u)
{
    if (g[u].size() == 0)
    {
        return a[u];
    }
    int new_val = 2e9;
    for (auto v : g[u])
    {
        a[v] = dfs(g, n, a, v);
        new_val = min(new_val, a[v]);
    }
    if (u == 0)
    {
        a[u] += new_val;
        return a[u];
    }
    if (new_val >= a[u])
        new_val = (a[u] + new_val) / 2;
    a[u] = new_val;
    return a[u];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> z(n - 1);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> z[i];
        g[z[i] - 1].push_back(i + 1);
    }
    cout << dfs(g, n, a, 0) << '\n';
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