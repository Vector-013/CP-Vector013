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
    vector<int> a(n), v(n);
    for (auto &x : a)
        cin >> x;
    ll ans = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < n; i++)
        v[i] = n - i - a[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < k; i++)
        ans += v[i];
    ans -= 1ll * k * (k + 1) / 2ll;
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