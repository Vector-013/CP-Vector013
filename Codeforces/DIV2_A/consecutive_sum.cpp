#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
using namespace std;
const int INF = 2e9;
typedef long long ll;
typedef long double ld;
#define pb push_back
ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}

void solve()
{
    ll n, k, a;
    cin >> n >> k;
    vector<vector<int>> v(k);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        v[i % k].pb(a);
    }
    ll sum = 0;
    for (int j = 0; j < k; j++)
        sum += *max_element(v[j].begin(), v[j].end());
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