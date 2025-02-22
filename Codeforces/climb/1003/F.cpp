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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int>> g(n);
    string s = string(n, '0');
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        if (a[x] == a[y])
            s[a[x] - 1] = '1';
    }
    for (int i = 0; i < n; i++)
    {
        map<int, int> mp;
        mp[a[i]]++;
        for (auto v : g[i])
            mp[a[v]]++;

        for (auto [x, y] : mp)
            if (y >= 2)
                s[x - 1] = '1';
    }
    cout << s << "\n";
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
