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
    ll n, m, d;
    ll sum = 0, last, req = 0;
    cin >> n >> m >> d;
    vector<ll> v(n);
    set<pair<ll, ll>> s;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        last = sum + v[i] - ((i + 1) * d);
        req = max(req, last);
        if (v[i] > 0)
        {
            s.insert({v[i], i + 1});
            sum += v[i];
        }
        if (s.size() >= m)
        {
            sum -= (*s.begin()).first;
            s.erase(s.begin());
        }
    }
    cout << req << '\n';
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