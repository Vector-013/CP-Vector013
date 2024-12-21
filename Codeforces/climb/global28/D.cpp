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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = max(a[i], a[0]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        if (b[i] <= a[0])
            b[i] = inf;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < m; i++)
    {
        b[i] = a.end() - lower_bound(a.begin(), a.end(), b[i]);
        // cout << b[i] << " \n"[i == m - 1];
    }

    for (int k = 1; k <= m; k++)
    {
        ll ans = 0;
        for (int j = k - 1; j < m; j += k)
        {
            ans += b[j] + 1;
        }
        cout << ans << " \n"[k == m];
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