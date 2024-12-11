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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for (int dif = 0; dif < n; dif++)
    {
        ll min1 = linf, min2 = linf;
        if (dif == 0)
        {
            for (int i = dif; i < n; i++)
            {
                min1 = min(min1, a[i][i - dif]);
            }
            ans += (min1 < 0) ? -min1 : 0;
        }
        else
        {
            for (int i = dif; i < n; i++)
            {
                min1 = min(min1, a[i][i - dif]);
                min2 = min(min2, a[i - dif][i]);
            }
            ans += (min1 < 0) ? -min1 : 0;
            ans += (min2 < 0) ? -min2 : 0;
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