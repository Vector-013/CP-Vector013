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

ll coins(vector<ll> dp, vector<ll> x, ll n)
{
    if (dp[n] != -1)
        return dp[n];
    ll mini = linf;
    for (int i = 0; i < x.size(); i++)
    {
        mini = (min(mini, coins(dp, x, n - x[i])) + 1);
    }
    dp[n] = mini;
    return mini;
}

void solve()
{
    ll q, n, a;
    cin >> q >> n;
    vector<ll> x(q);
    vector<ll> dp(1e6 + 2, -1);
    for (int i = 0; i < q; i++)
    {
        cin >> x[i];
        dp[x[i]] = 1ll;
    }
    ll ans = coins(dp, x, n);
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}