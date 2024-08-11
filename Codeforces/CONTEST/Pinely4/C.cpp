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
ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (v.size() == 1)
    {
        cout << 1 << '\n'
             << v[0] << '\n';
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] % 2 != v[i - 1] % 2)
        {
            cout << -1 << '\n';
            return;
        }
    }

    ll cnt = 1;
    ll k = power(2, 30);
    while (cnt <= 30)
    {
        for (int i = 0; i < n; i++)
        {
            v[i] = abs(v[i] - k);
        }
        k >> 1;
    }
    if (v[0] == 1)
    {
        cout << 31 << '\n';
        k = power(2, 30);
        while (k)
        {
            cout << k << ' ';
            k >> 1;
        }
        cout << 1 << '\n';
        return;
    }
    cout << 30 << '\n';
    k = power(2, 30);
    while (k)
    {
        cout << k << ' ';
        k >> 1;
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}