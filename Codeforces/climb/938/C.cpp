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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i= 0; i < n; i++)
        cin >> a[i];
    vector<ll> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i - 1];
    for (int i = 1; i <= n; i++)
        suf[i] = suf[i - 1] + a[n - i];
    ll f = (k + 1ll) / 2ll;
    ll b = k / 2ll;
    ll loc1 = upper_bound(pre.begin(), pre.end(), f) - pre.begin();
    ll loc2 = upper_bound(suf.begin(), suf.end(), b) - suf.begin();
    loc1--;
    loc2--;
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if (loc1 + loc2 >= n || k >= sum)
    {
        cout << n << '\n';
        return;
    }
    cout << min(n, loc1 + loc2) << '\n';
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