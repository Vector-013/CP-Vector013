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
    map<int, vector<int>> mp;
    for (int i = 0; i < n * m; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    int cur = 0, row = 1;
    vector<vector<int>> loc(n + 1, vector<int>(m + 1));

    for (auto s : mp)
    {
        vector<int> v = s.second;
        vector<pair<int, int>> z, w;
        for (auto i : v)
        {
            cur++;
            if (cur == m + 1)
            {
                cur = 1;
                row++;
            }
            z.push_back({row, -cur});
        }
        sort(z.begin(), z.end());
        for (int i = 0; i < z.size(); i++)
            loc[z[i].first][-z[i].second] = v[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int c = 1; c < j; c++)
            {
                if (loc[i][j] > loc[i][c])
                {
                    ans++;
                }
            }
        }
    }
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