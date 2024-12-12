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
    int n;
    cin >> n;
    vector<ll> v(n), a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll cur = abs(a[1] - b[1]);
    ll ans = -linf;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            cur += v[i] + 1;
            ans = max(ans, cur);
            continue;
        }
        else if (a[i + 1] == b[i + 1])
        {
            cur += v[i] + 1ll;
            ans = max(ans, cur);
            cur = 0;
        }
        else
        {
            cur += v[i] + 1ll - abs(a[i + 1] - b[i + 1]);
            ll tmpcur = cur + abs(a[i + 1] - b[i + 1]);
            cur = max(cur, abs(a[i + 1] - b[i + 1]));
            ans = max(ans, tmpcur);
        }
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