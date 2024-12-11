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
    ll x, y, k, ans = 0;
    cin >> x >> y >> k;
    ll sx = x != 0 ? x / k + ((x % k)!=0) : 0;
    ll sy = y != 0 ? y / k + ((y % k)!=0) : 0;

    if (sx > sy)
    {
        ans = 2 * sx - 1;
    }
    else
    {
        ans = 2 * sy;
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