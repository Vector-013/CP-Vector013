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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
        if (a[i] == n)
            a[i]--;
    }
    sort(a.begin(), a.end());
    vector<int> suf(m + 1, 0);
    for (int i = m - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    int ans = 0;
    for (int i = 0; i < m - 1; ++i)
    {
        auto idx = lower_bound(a.begin() + i + 1, a.end(), n - a[i]) - a.begin();
        int req = suf[idx] - (n - a[i] - 1) * (m - idx);
        ans += 2 * req;
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}