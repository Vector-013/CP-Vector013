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
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
ll min(ll a, ll b)
{
    if (a <= b)
        return a;
    else
        return b;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> s(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + v[i - 1];
    }

    map<ll, ll> m;
    ll ans = 0;

    for (int i = 0; i <= n; i++)
    {
        if (m[s[i]] == 1)
        {
            ans++;
            m.clear();
        }
        m[s[i]] = 1;
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