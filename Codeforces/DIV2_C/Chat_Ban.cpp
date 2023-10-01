#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
bool pair_first_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}
bool isprime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = sqrt(n); i >= 2; i--)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void solve()
{
    ll k, x, ans;
    cin >> k >> x;
    ll sum = 0;
    if (x <= k * (k + 1) / 2)
    {
        ll s = 0ll, e = k + 1;
        ll a = (s + e) / 2ll;
        while (!(a * (a + 1) / 2 >= x && (a - 1) * a / 2 < x))
        {
            a = (s + e) / 2ll;
            if (a * (a + 1ll) / 2ll < x)
                s = a;
            else if (a * (a + 1ll) / 2ll > x)
                e = a;
            else
                break;
        }
        cout << a << '\n';
        return;
    }
    else if (x > k * (k + 1) / 2 && x <= k * k)
    {
        x = k * k - x + 1;
        ll s = 0ll, e = k;
        ll a = (s + e) / 2;
        while (!(a * (a + 1ll) / 2ll >= x && (a - 1ll) * a / 2ll < x))
        {
            a = (s + e) / 2ll;
            if (a * (a + 1ll) / 2ll < x)
                s = a;
            else if (a * (a + 1ll) / 2ll > x)
                e = a;
            else
                break;
        }
        cout << 2 * k - a << '\n';
        return;
    }
    else
    {
        cout << 2 * k - 1 << '\n';
        return;
    }
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