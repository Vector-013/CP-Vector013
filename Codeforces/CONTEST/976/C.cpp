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
    ll b, c, d, a = 0;
    cin >> b >> c >> d;

    for (int i = 0; i < 62; i++)
    {
        int bb = (b >> i) & 1, cb = (c >> i) & 1, db = (d >> i) & 1;

        if (db == 1)
        {
            if (bb == 0 && cb == 1)
            {
                cout << -1 << '\n';
                return;
            }
            if (bb && cb)
            {
                a |= 0ll << i;
            }
            else
            {

                a |= 1ll << i;
            }
        }
        else
        {
            if (bb == 1 && cb == 0)
            {
                cout << -1 << '\n';
                return;
            }
            if (bb && cb)
            {
                a |= 1ll << i;
            }
        }
    }
    cout << a << '\n';
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