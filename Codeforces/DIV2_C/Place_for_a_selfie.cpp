#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
using namespace std;
const int INF = 2e9;
typedef long long ll;
typedef long double ld;
ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}

void solve()
{
    ll n, m, a, b, c, d;
    bool flag;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        flag = true;
        if (c < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int low = lower_bound(v.begin(), v.end(), b) - v.begin();
        for (auto x : {low - 1, low})
        {
            if (x < 0 || x >= n)
                continue;

            d = (b - v[x]) * (b - v[x]) - 4ll * a * c;
            if (d < 0)
            {
                cout << "YES" << endl
                     << v[x] << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "NO" << endl;
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