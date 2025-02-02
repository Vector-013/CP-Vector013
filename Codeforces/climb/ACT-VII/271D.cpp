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
    int t, k;
    cin >> t >> k;
    vector<ll> dp(100001, 0ll);
    for (int i = 0; i < k; i++)
        dp[i] = 1ll;
    for (int i = k; i <= 100000; i++)
        dp[i] = (dp[i - 1] + dp[i - k]) % mod;
    vector<ll> pref(100001, 0ll);
    for (int i = 1; i <= 100000; i++)
        pref[i] = (pref[i - 1] + dp[i]) % mod;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (pref[b] - pref[a - 1]+mod)%mod << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}
