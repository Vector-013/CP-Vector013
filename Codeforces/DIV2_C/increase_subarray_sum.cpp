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
const int inf = 2e9;
typedef long long ll;
typedef long double ld;
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
    int n, x, tsum = 0;
    cin >> n >> x;
    vector<int> v(n);
    vector<int> lensum(n + 1, -inf);
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int l = 0; l < n; l++)
    {
        tsum = 0;
        for (int r = l; r < n; r++)
        {
            tsum += v[r];
            lensum[r - l + 1] = max(lensum[r - l + 1], tsum);
        }
    }
    for (int k = 0; k <= n; k++)
    {
        ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = max(ans, lensum[i] + min(k, i) * x);
        }
        cout << ans << " \n"[k == n];
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