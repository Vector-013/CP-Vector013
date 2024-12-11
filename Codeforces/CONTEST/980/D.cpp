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
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i]--;
    }

    vector<ll> z(n, linf);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(0ll, 0ll);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (z[u] != linf)
            continue;

        z[u] = d;
        pq.emplace(d + a[u], b[u]);

        if (u > 0)
            pq.emplace(d, u - 1ll);
    }
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans = max(ans, sum - z[i] * 1ll);
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