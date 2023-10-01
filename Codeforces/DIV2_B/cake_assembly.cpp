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
ll modder(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;

    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;

        b >>= 1;
    }

    return res;
}
ll maxsub(vector<int> v)
{
    int s = 0, start = 0;
    int e = 0, end = 0;
    ll currsum = 0;
    ll maxsum = -linf;
    for (int i = 0; i < v.size(); i++)
    {
        currsum += v[i];
        if (maxsum < currsum)
        {
            end = i;
            start = s;
            maxsum = currsum;
        }
        if (currsum < 0)
        {
            currsum = 0;
            s = i + 1;
        }
    }
    return maxsum;
}
int gcd(int a, int b)
{
    int result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
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
/*---------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    ll n, w, h, fdif, bdif, fmax = -inf, bmin = inf;
    cin >> n >> w >> h;
    bool f = false, b = false;
    vector<ll> k(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        if (f == 0 && k[i] + w < c[i] + h)
            f = 1;
        else if (b == 0 && k[i] - w > c[i] - h)
            b = 1;
    }
    if (b == 0 && f == 0)
    {
        cout << "YES" << '\n';
        return;
    }
    if (f == 1 && b == 1)
    {
        cout << "NO" << '\n';
        return;
    }
    if (f == 1)
    {
        for (int i = 0; i < n; i++)
        {
            fdif = c[i] + h - k[i] - w;
            bdif = c[i] - h - k[i] + w;
            fmax = max(fmax, fdif);
            bmin = min(bmin, bdif);
        }
        if (fmax <= bmin)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        return;
    }
    if (b == 1)
    {
        fmax = inf, bmin = -inf;
        for (int i = 0; i < n; i++)
        {
            fdif = -c[i] - h + k[i] + w;
            bdif = -c[i] + h + k[i] - w;
            fmax = min(fmax, fdif);
            bmin = max(bmin, bdif);
        }
        if (bmin <= fmax)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
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