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
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    ll n, k;
    cin >> n >> k;

    ll r = n;
    ll l = 0;
    ll ans = linf;

    while (l <= r)
    {
        ll x = (l + r) / 2;
        ll rval = k * (n - x) + ((n - 1) * n) / 2 - ((x - 1) * x) / 2;
        ll lval = k * x + ((x - 1) * x) / 2;
        ans = min(ans, abs(rval - lval));

        if (rval - lval > 0)
        {
            l = x + 1;
        }
        else if (rval - lval < 0)
        {
            r = x - 1;
        }
        else
            break;
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