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
    int n, x;
    cin >> n >> x;
    int a, b, c, lim;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n / i); j++)
        {
            a = i;
            b = j;
            lim = min(x - a - b, (n - a * b) / (a + b));
            lim = max(lim, 0);
            ans += lim;
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