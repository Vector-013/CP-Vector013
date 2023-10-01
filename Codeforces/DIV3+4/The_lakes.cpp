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
ll n, m;
vector<vector<int>> v;
vector<vector<bool>> w;
ll dfs(ll i, ll j)
{
    if ((v[i][j] == 0) || (w[i][j] == 0))
        return 0;
    ll sum = v[i][j];
    w[i][j] = false;
    sum += dfs(i + 1, j) + dfs(i, j + 1) + dfs(i - 1, j) + dfs(i, j - 1);
    return sum;
}
void solve()
{
    ll maxi = -inf;
    cin >> n >> m;
    v.assign(n + 2, vector<int>(m + 2, 0));
    w.assign(n + 2, vector<bool>(m + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] != 0)
                w[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            maxi = max(maxi, dfs(i, j));
    cout << maxi << '\n';
    v.clear();
    w.clear();
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