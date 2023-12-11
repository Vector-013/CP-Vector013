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

ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}
void solve()
{
    ll n, k, p;
    cin >> n;

    ll ans = 1;
    for (int i = 18; i >= 0; i--)
    {
        p = power(10, i);
        k = n / p;
        n = n % p;
        ans *= (k + 2) * (k + 1) / 2ll;
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