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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> order;
    vector<set<int>> vs(n);
    set<int> s;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]] = i;
            vs[i].insert(a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
        order.push_back(mp[i]);
    for (int j = 0; j < n; ++j)
        s.insert(order[j]);
    if (s.size() != n)
    {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    for (auto z : s)
        ans.push_back(z);
    for (int i = n; i < n * m; i++)
    {
        if (vs[order[i % n]].count(i))
        {
            ans.push_back(order[i % n]);
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; i++)
        cout << order[i] + 1 << " \n"[i == n - 1];
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