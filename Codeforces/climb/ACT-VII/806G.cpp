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
    vector<ll> pre(n, 0), suf(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll s = accumulate(a.begin(), a.end(), 0ll);
    ll ans = s -= k * n;
    pre[0] = 0;
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    
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
