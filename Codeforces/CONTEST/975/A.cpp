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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll s1 = 0;
    ll s2 = 0, maxi1 = -linf, maxi2 = -linf;
    for (int i = 0; i < n; i += 2)
    {
        s1++;
        maxi1 = max(maxi1, v[i]);
    }
    s1 += maxi1;
    for (int i = 1; i < n; i += 2)
    {
        s2++;
        maxi2 = max(maxi2, v[i]);
    }
    s2 += maxi2;
    cout << max(s1, s2) << ' ';
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