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
        cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    ll a = 0, b = 0;
    for (int i = 0; i < n; i += 2)
    {
        // if ((i % 2) == 0)
        // {
        //     a += v[i];
        // }
        // else
        // {
        //     b += v[i];
        // }
        if ((i + 1 < n) && k && ((v[i] - v[i + 1]) <= k))
        {
            k -= (v[i] - v[i + 1]);
        }
        else if ((i + 1 < n) && k && ((v[i] - v[i + 1]) > k))
        {
            a += (v[i] - v[i + 1] - k);
            k = 0;
        }
        else if ((i + 1 < n) && !k)
        {
            a += (v[i] - v[i + 1]);
        }
        else if (i == n - 1)
        {
            a += v[i];
        }
    }
    cout << a << '\n';
    // if ((a - b) <= k)
    // {
    //     cout << 0 << '\n';
    //     return;
    // }
    // cout << a - b - k << '\n';
    // return;
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