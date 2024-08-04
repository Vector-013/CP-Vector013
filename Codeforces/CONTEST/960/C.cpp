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
    ll n, x, y;
    cin >> n;
    vector<ll> v(n);
    vector<ll> mad(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    mad[0] = 0;
    ll msf = 0;
    map<ll, ll> m;
    m[v[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        if (m[v[i]] && v[i] > msf)
        {
            msf = v[i];
        }
        mad[i] = msf;
        m[v[i]]++;
    }
    for (int i = 0; i < n; i++)
        sum += mad[i];

    v = mad;
    map<ll, ll> p;
    msf = 0;
    p[v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (p[v[i]] && v[i] > msf)
        {
            msf = v[i];
        }
        mad[i] = msf;
        p[v[i]]++;
    }

    for (int i = n - 1; i >= 0; i--)
        sum += mad[i] * (n - i);
    cout << sum << '\n';
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