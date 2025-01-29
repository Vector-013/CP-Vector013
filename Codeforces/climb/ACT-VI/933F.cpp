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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), d(m), f(k), dd(n - 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> f[i];
    }
    sort(a.begin(), a.end());
    int maxd = 0, ele, target;
    for (int i = 1; i < n; i++)
    {
        int dodo = a[i] - a[i - 1];
        dd[i - 1] = dodo;
        if (dodo > maxd)
        {
            maxd = dodo;
            ele = i - 1;
            target = a[i - 1] + (dodo + 1) / 2;
        }
    }
    sort(dd.begin(), dd.end());
    sort(d.begin(), d.end());
    sort(f.begin(), f.end());
    int diff = maxd;
    for (int i = 0; i < m; i++)
    {
        int idx = upper_bound(f.begin(), f.end(), target - d[i]) - f.begin();
        if (idx < k)
            diff = min(diff, max(abs(a[ele] - f[idx] - d[i]), abs(a[ele + 1] - f[idx] - d[i])));
        if (idx > 0)
            diff = min(diff, max(abs(a[ele] - f[idx - 1] - d[i]), abs(a[ele + 1] - f[idx - 1] - d[i])));
    }
    cout << max(diff, (n >= 3) ? dd[n - 3] : -inf) << '\n';
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
