#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
bool pair_first_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}

void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll cnt = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        cnt += upper_bound(v.begin() + i + 1, v.end(), r - v[i]) - lower_bound(v.begin() + i + 1, v.end(), l - v[i]);
    }
    cout << cnt << '\n';
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