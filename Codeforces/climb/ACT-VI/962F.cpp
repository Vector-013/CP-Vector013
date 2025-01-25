#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll l = 0;
    ll r = 1e9 + 1;
    ll mid = (l + r) / 2;

    auto check = [&](ll mid) -> bool
    {
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid > a[i])
                continue;
            cnt += (a[i] - mid) / b[i] + 1;
        }
        return cnt >= k;
    };

    while (r > l + 1)
    {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    ll ans = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < l)
            continue;
        int cc = (a[i] - l) / b[i] + 1;
        ans += 1ll * cc * a[i] - 1ll * b[i] * cc * (cc - 1) / 2;
        s += cc;
    }
    ans -= 1ll * (s - k) * l;
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