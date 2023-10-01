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
    int n;
    cin >> n;
    vector<int> v;
    v.pb(n);
    int cur = n, lst;
    int p = 0;
    bool bol = true;
    vector<bool> bits(32, false);
    for (int i = 32; i >= 0; i--)
    {
        if (cur >= power(2, i))
        {
            if (bol)
                lst = i;
            bits[i] = true;
            bol = 0;
            cur -= power(2, i);
        }
    }
    cur = n;
    for (int i = 0; i < lst; i++)
    {
        if (bits[i])
        {
            cur -= power(2, i);
            v.pb(cur);
        }
    }
    for (int i = lst - 1; i >= 0; i--)
        v.pb(power(2, i));

    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
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