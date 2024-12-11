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

void solve()
{
    ll x, m;
    cin >> x >> m;
    ll ans = 0;
    ll n = 1;
    while (n <= x)
    {
        n <<= 1;
    }
    ll q = min(n, m + 1);
    for (int i = 1; i < q; i++)
    {
        ll z = x ^ i;
        if ((z != 0) && ((x % z == 0) || (i % z == 0)))
            ans++;
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
    {
        solve();
    }
}