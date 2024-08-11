#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n, x, a;
    cin >> n >> x;
    vector<ll> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        v[i] = v[i - 1] + a;
    }
    vector<ll> dp(n + 2);
    dp[n] = 0;
    dp[n + 1] = 0;
    int q;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        q = upper_bound(v.begin() + i, v.end(), v[i] + x) - v.begin();
        dp[i] = dp[q] + q - i - 1;
        ans += dp[i];
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