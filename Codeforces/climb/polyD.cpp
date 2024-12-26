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
    ll n, m;
    cin >> n >> m;
    ll cnt = 0;
    vector<vector<ll>> v(n, vector<ll>(m));
    vector<ll> row(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            cnt += v[i][j];
            row[i] += v[i][j];
        }
    }
    if (cnt % n)
    {
        cout << -1 << '\n';
        return;
    }
    vector<tuple<ll, ll, ll>> ans;
    ll trg = cnt / n;
    ll f = -1;
    ll l = -1;
    ll b = 0;
    for (int i = 0; i < n; i++)
    {
        if (row[i] < trg && f == -1)
            f = i;
        if (row[i] > trg && l == -1)
            l = i;
        if (row[i] != trg)
            b++;
    }
    while (b)
    {
        for (int i = 0; i < m; i++)
        {
            if (v[l][i] == 1 && v[f][i] == 0)
            {
                v[l][i] = 0;
                v[f][i] = 1;
                ans.push_back({f + 1, l + 1, i + 1});
                row[f]++;
                row[l]--;
            }
            if (row[l] == trg)
                break;
            if (row[f] == trg)
                break;
        }
        if (row[f] == trg)
            b--;
        if (row[l] == trg)
            b--;
        while (b > 0 && !(row[l % n] > trg))
        {
            l++;
        }
        l %= n;
        while (b > 0 && !(row[f % n] < trg))
        {
            f++;
        }
        f %= n;
    }
    cout << (ll)ans.size() << '\n';
    for (auto [a, b, c] : ans)
        cout << a << ' ' << b << ' ' << c << '\n';
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