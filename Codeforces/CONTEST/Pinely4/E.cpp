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

void dfs(vector<vector<int>> &g, vector<int> &color, bool &alice, vector<vector<int>> &colorv, int n, int pcolor, int p, int v)
{
    if (color[v] != 0)
    {
        if (color[v] == pcolor)
            alice = 1;
        return;
    }
    color[v] = 3 - pcolor;
    colorv[3 - pcolor].push_back(v + 1);
    for (auto u : g[v])
        if (u != p)
            dfs(g, color, alice, colorv, n, color[v], v, u);
}

void solve()
{
    int n, a, b, m, y;
    int x, z;
    bool alice = 0;
    cin >> n >> m;
    vector<vector<int>> colorv(3, vector<int>());
    vector<int> color(n);
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(g, color, alice, colorv, n, 2, -1, 0);
    if (alice)
    {
        cout << "Alice" << endl;
        cout.flush();
        for (int i = 0; i < n; i++)
        {
            cout << 1 << " " << 2 << endl;
            cout.flush();
            cin >> x >> z;
        }
        return;
    }
    else
    {
        cout << "Bob" << endl;
        cout.flush();

        for (int i = 0; i < n; i++)
        {
            cin >> x >> z;
            if (x + z == 3)
            {
                x = 1, z = 2;
                if (colorv[1].size())
                {
                    cout << colorv[1][colorv[1].size() - 1] << " " << 1 << endl;
                    cout.flush();
                    colorv[1].pop_back();
                    continue;
                }
                cout << colorv[2][colorv[2].size() - 1] << " " << 2 << endl;
                cout.flush();
                colorv[2].pop_back();
                continue;
            }
            if (x + z == 4)
            {
                x = 1, y = 3;
                if (colorv[1].size())
                {
                    cout << colorv[1][colorv[1].size() - 1] << " " << 1 << endl;
                    cout.flush();
                    colorv[1].pop_back();
                    continue;
                }
                cout << colorv[2][colorv[2].size() - 1] << " " << 3 << endl;
                cout.flush();
                colorv[2].pop_back();
                continue;
            }
            if (x + z == 5)
            {
                x = 2, y = 3;
                if (colorv[2].size())
                {
                    cout << colorv[2][colorv[2].size() - 1] << " " << 2 << endl;
                    cout.flush();
                    colorv[2].pop_back();
                    continue;
                }
                cout << colorv[1][colorv[1].size() - 1] << " " << 3 << endl;
                cout.flush();
                colorv[1].pop_back();
                continue;
            }
        }
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