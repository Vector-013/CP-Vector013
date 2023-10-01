#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
#include <map>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
bool pair_first_sort(pair<int, string> p1, pair<int, string> p2)
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
    int n, sum = 0;
    cin >> n;
    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    bool s1 = 1, s2 = 1;
    sort(v.begin(), v.end(), pair_first_sort);
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == "11")
        {
            if (!(s1 == 0 && s2 == 0) || (s1 == 0 && s2 == 0 && v[i].first < sum))
            {
                cout << v[i].first << '\n';
                return;
            }
        }
        if (s1 && v[i].second == "10")
        {
            s1 = 0;
            sum += v[i].first;
        }
        if (s2 && v[i].second == "01")
        {
            s2 = 0;
            sum += v[i].first;
        }
    }
    if (s2 == 0 && s1 == 0)
    {
        cout << sum << '\n';
        return;
    }
    else
    {
        cout << -1 << '\n';
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