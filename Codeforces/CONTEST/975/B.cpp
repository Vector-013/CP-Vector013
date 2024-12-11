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
    ll n, q;
    cin >> n >> q;
    vector<int> v(n);
    map<ll, ll> m1, m2;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        m1[v[i]] = i * (n - i - 1);
        m2[i * (n - i - 1ll) + (n - 1ll)]++;
    }
    for (int i = 1; i < n; i++)
    {
        m2[i * (n - i)] += v[i] - v[i - 1] - 1;
    }
    ll k;
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        cout << m2[k] << ' ';
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
        solve();
}