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

ll tasks(vector<ll> v, ll mid, ll t)
{
    ll ans = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        ans += ((mid / v[i]));
        if (ans >= t)
            return 1;
    }
    return -1;
}
void solve()
{
    ll n, t, ans, lim = -linf, mini = linf;
    cin >> n >> t;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        lim = max(lim, t * v[i]);
        mini = min(v[i], mini);
    }
    ll s = mini, e = lim, mid;
    while (s < e)
    {
        mid = (s + e) / 2ll;
        if (tasks(v, mid, t) == 1)
        {
            e = mid;
        }
        else
            s = mid + 1ll;
    }
    cout << s << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}