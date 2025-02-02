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
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int max1 = -1, max2 = -1;
    for (int i = 0; i < n; i++)
    {
        int t = g[i].size();
        if (t > max1)
        {
            max2 = max1;
            max1 = g[i].size();
        }
        else if (t > max2)
        {
            max2 = g[i].size();
        }
    }
    set<int> m1, m2;
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == max1)
            m1.insert(i);
        else if (g[i].size() == max2)
            m2.insert(i);
    }
    int f = m1.size();
    if (f == 1)
    {
        bool yes = false;
        int trg = -1;
        set<int> s(g[*m1.begin()].begin(), g[*m1.begin()].end());
        for (auto u : m2)
        {
            if (s.find(u) == s.end())
            {
                yes = true;
                break;
            }
        }
        if (yes)
            cout << max1 + max2 - 1 << '\n';
        else
            cout << max1 + max2 - 2 << '\n';
        return;
    }
    else if (f == 2)
    {
        int x = *m1.begin(), y = *m1.rbegin();
        if (find(g[x].begin(), g[x].end(), y) != g[x].end())
            cout << max1 + max1 - 2 << '\n';
        else
            cout << max1 + max1 - 1 << '\n';
        return;
    }
    cout << 2 * max1 - 1 << '\n';
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