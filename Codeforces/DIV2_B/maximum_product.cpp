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
bool mod_first_sort(int a, int b)
{
    return abs(a) < abs(b);
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
/*/--------------------------------------------------------------------------------------------------------------------/*/
void solve()
{
    ll n, p = 0, q = 0, ans = 1ll, temp = 1ll;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] > 0)
            p++;
    }
    sort(v.begin(), v.end(), mod_first_sort);
    for (int i = n - 5; i < n; i++)
        ans *= v[i];
    if (n == 5 || p == 0)
        cout << v[0] * v[1] * v[2] * v[3] * v[4] << '\n';
    else
    {
        for (int i = 0; i < n - 5; i++)
        {
            for (int k = n - 5; k < n; k++)
            {
                temp = v[i];
                for (int j = n - 5; j < n; j++)
                {
                    if (j == k)
                        continue;
                    temp *= v[j];
                }
                ans = max(ans, temp);
            }
        }
        cout << ans << '\n';
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