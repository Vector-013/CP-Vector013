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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n, -1);
    x--;
    y--;
    vector<set<int>> g(n);
    g[x].insert(y);
    g[y].insert(x);
    for (int i = 0; i < n; i++)
    {
        g[i].insert((i + 1) % n);
        g[i].insert((i - 1 + n) % n);
    }
    auto mex = [](set<int> &s) -> int
    {
        int mex = 0;
        while (s.count(mex))
            mex++;
        return mex;
    };

    for (int i = 0; i < n; ++i)
    {
        set<int> s;
        for (auto &j : g[i])
        {
            if (a[j] != -1)
                s.insert(a[j]);
        }
        a[i] = mex(s);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n - 1];
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