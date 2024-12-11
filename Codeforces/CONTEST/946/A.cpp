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
    int x, y;
    cin >> x >> y;
    int ans = y / 2;
    if (y % 2)
    {
        ans++;
        if (x > (7 * (ans - 1) + 11))
        {
            x -= 7 * (ans - 1) + 11;
            ans += (x / 15) + (x % 15 != 0);
        }
    }
    else
    {
        if (x > (7 * ans))
        {
            x -= 7 * ans;
            ans += (x / 15) + (x % 15 != 0);
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