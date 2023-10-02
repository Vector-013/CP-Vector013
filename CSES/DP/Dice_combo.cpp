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
ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 2, 0);
    dp[1] = 1;
    for (ll i = 2; i <= 6; i++)
        dp[i] = (ll)(1 << i - 1);
    for (ll i = 7; i <= n; i++)
    {
        for (ll j = 1; j <= 6; j++)
            dp[i] = (dp[i] + dp[i - j]) % mod;
    }
    cout << dp[n] % mod << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}