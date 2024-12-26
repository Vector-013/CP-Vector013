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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        v.push_back(b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = -1;
    for (int i = 0; i < 2 * n; ++i)
    {
        int j1 = lower_bound(b.begin(), b.end(), v[i]) - b.begin();
        int j2 = lower_bound(a.begin(), a.end(), v[i]) - a.begin();

        int neg = j2 - j1;
        // cout << "neg: " << neg << '\n';
        if (neg > k)
            continue;
        ans = max(ans, 1ll * v[i] * (n - j1));
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