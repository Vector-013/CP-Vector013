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
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const ll mod = 1e9 + 7;
ll min(ll a, ll b)
{
    if (a <= b)
        return a;
    else
        return b;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    n %= mod;

    if (k == 1)
    {
        cout << n << '\n';
        return;
    }
    ll a = 1, b = 1, c = 1;

    while (a != 0)
    {
        ll q = (a + b) % k;
        a = b;
        b = q;
        c++;
    }

    ll ans = n * (c % mod) % mod;
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