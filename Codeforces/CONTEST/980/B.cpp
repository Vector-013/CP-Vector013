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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n >= k)
    {
        cout << k << '\n';
        return;
    }
    sort(v.begin(), v.end());
    ll ans = k;
    // find prefix sum
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    ll check = 0;
    for (int i = 0; i < n; i++)
    {
        check = prefix[i] + v[i] * (n - i);
        if (check < k)
        {
            ans++;
        }
        else
        {
            cout << ans << '\n';
            return;
        }
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