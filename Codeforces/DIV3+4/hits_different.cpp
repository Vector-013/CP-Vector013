#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
vector<vector<ll>> w;

vector<ll> q(2023, 0); // n n+1 /2
ll cnt(int i, int j)
{
    ll sum = 0;
    if ((i < 0) || (j < 0))
        return 0;
    if (w[i][j] != -1)
        return w[i][j];
    if (i == j)
    {
        w[i][j] = (q[i] * q[i]) + cnt(i - 1, j - 1);
        return w[i][j];
    }
    if (j == 0)
    {
        w[i][j] = power(q[i - 1] + 1, 2) + cnt(i - 1, 0);
        return w[i][j];
    }
    sum += cnt(i - 1, j) + cnt(i - 1, j - 1) - cnt(i - 2, j - 1) + power((j + 1 + q[i - 1]), 2);
    w[i][j] = sum;
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    w.assign(2023, vector<ll>(2023, -1));
    w[0][0] = 1;
    q[0] = 1;
    for (int i = 1; i < 2023; i++)
        q[i] = i + 1 + q[i - 1];
    while (t--)
    {
        int n;
        int r = 0, d = 0;
        cin >> n;
        for (int i = 1; i < 2023; i++)
            if ((n > q[i - 1]) && (n <= q[i]))
            {
                r = i;
                d = n - q[i - 1] - 1;
            }
        w[r][d] = cnt(r, d);
        cout << w[r][d] << '\n';
    }
}