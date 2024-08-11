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

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll m = v[n - 1];
    ll a = 0, t = -linf, cur;
    ll l = v[n - 1], h = v[n - 1] + k - 1;

    for (ll i = 0; i < n; i++)
    {
        cur = (v[i] + 2 * k * ceil(((double)(v[n - 1] - v[i])) / ((double)(2 * k))));

        if (cur > v[n - 1] + k)
        {
            cur -= k + 1;
            h = min(h, cur);
        }
        else if (cur == v[n - 1] + k)
        {
            cout << -1 << '\n';
            return;
        }
        else
        {
            l = max(l, cur);
        }
    }
    if (l <= h)
    {
        cout << l << '\n';
        return;
    }
    else
    {
        cout << -1 << '\n';
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