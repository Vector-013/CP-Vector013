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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 2; i++)
    {
        ans += mp[{v[i], v[i + 1]}];
        mp[{v[i], v[i + 1]}]++;
    }
    mp.clear();
    for (int i = 0; i < n - 2; i++)
    {
        ans += mp[{v[i], v[i + 2]}];
        mp[{v[i], v[i + 2]}]++;
    }
    mp.clear();
    for (int i = 0; i < n - 2; i++)
    {
        ans += mp[{v[i + 1], v[i + 2]}];
        mp[{v[i + 1], v[i + 2]}]++;
    }

    map<tuple<int, int, int>, int> m;
    for (int i = 0; i + 2 < n; i++)
    {
        ans -= 3 * m[{v[i], v[i + 1], v[i + 2]}];
        m[{v[i], v[i + 1], v[i + 2]}]++;
    }
    cout << ans << "\n";
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