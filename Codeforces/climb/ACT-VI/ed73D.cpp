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
    int n;
    cin >> n;
    vector<ll> dp(3, linf), ndp(3, linf);
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    ll x = -3;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (x + j == a[i] + k)
                    continue;
                ndp[k] = min(ndp[k], dp[j] + b[i] * k);
            }
        }
        dp = ndp;
        ndp.assign(3, linf);
        x = a[i];
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
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