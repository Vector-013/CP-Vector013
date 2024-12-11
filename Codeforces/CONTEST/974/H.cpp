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
    vector<ll> xp(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    xp[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        xp[i] = xp[i - 1] ^ v[i];
        cout << xp[i] << " ";
    }
    int l, r;
    for (int i = 0; i < k; i++)
    {
        cin >> l >> r;
        l--;
        r--;
        if ((l - 1 >= 0ll) && ((xp[r] ^ xp[l - 1]) == 0ll))
        {
            cout << xp[r] << " "<<xp[l-1] << '\n';
            cout << "YES\n";
        }
        else if ((l == 0ll) && (xp[r] == 0ll))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
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