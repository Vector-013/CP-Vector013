#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    ll n, c;
    cin >> n >> c;
    ll ans = (c + 2) * (c + 1) / 2;
    vector<ll> s(n);
    array<ll, 2> cnt = {0, 0};
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        cnt[s[i] & 1]++;
        ans -= s[i] / 2 + 1;
        ans -= c - s[i] + 1;
    }
    ans += 1ll * (cnt[0] + 1) * cnt[0] / 2 + 1ll * (cnt[1] + 1) * cnt[1] / 2;
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
