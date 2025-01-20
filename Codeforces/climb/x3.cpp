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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<vector<int>> a(n, vector<int>(m));
    vector<set<int>> as(n, set<int>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            as[i].insert(a[i][j]);
            mp[a[i][j]] = i;
        }
    }
    vector<int> order;
    for (int i = 0; i < n; i++)
    {
        order.push_back(mp[i]);
    }

    set<int> s;
    for (int j = 0; j < n; j++)
    {
        s.insert(order[j]);
    }
    if (s.size() != n)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = n; i < n * m; i++)
    {
        if (as[order[i % n]].count(i))
        {
            continue;
        }
        else
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto i : order)
    {
        cout << i + 1 << ' ';
    }
    cout << '\n';
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