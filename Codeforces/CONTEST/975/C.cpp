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
    ll n, k, maxv = -linf, s = 0;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxv = max(maxv, v[i]);
        s += v[i];
    }
    ll ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (s >= maxv * i)
        {
            if (s % i == 0)
            {
                ans = i;
                continue;
            }
            else
            {
                if (k >= (i - (s % i)))
                {
                    ans = i;
                }
                continue;
            }
        }
        else
        {
            if (s + k >= maxv * i)
            {
                ans = i;
                continue;
            }
        }
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