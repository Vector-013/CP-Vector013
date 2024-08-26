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

ld dist(ll x1, ll y1, ll x2, ll y2)
{
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld d = dist(x1, y1, x2, y2);

    for (int i = 0; i < n; i++)
    {
        if (dist(x[i], y[i], x2, y2) <= d)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
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