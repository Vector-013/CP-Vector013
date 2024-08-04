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
    ll n;
    cin >> n;
    vector<ll> v;
    v.push_back(n);
    ll k = 1;
    ll cnt = 0;
    while (cnt <= 64)
    {
        if (n & k)
        {
            if (!(n & (~k)))
            {
                cout << 1 << '\n'
                     << n << '\n';
                return;
            }
            v.push_back((n & (~k)));
        }
        k = k << 1;
        cnt++;
    }
    cout << v.size() << '\n';
    for (ll i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
    cout << '\n';
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