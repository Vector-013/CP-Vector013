#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> z(n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    int r = 1;
    sort(v.begin(), v.end(), greater());
    int cur = v[0].first;
    for (int i = 0; i < n; ++i)
    {
        if (v[i].first != cur)
        {
            r = i + 1;
            cur = v[i].first;
        }
        z[v[i].second] = r;
    }
    for (auto &x : z)
        cout << x << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}