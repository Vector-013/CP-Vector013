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

ll num(vector<ll> x, ll mid, ll k)
{
    ll ans = 0, curr = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (curr + x[i] <= mid)
            curr += x[i];
        else
        {
            if (x[i] > mid)
            {
                return k + 1;
            }
            ans++;
            curr = x[i];
        }
    }
    ans++;
    return ans;
}
void solve()
{
    ll n, k, maxi = 0, mini = linf;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        maxi += x[i];
        mini = min(mini, x[i]);
    }
    ll s = mini, mid;
    ll e = maxi;
    while (s <= e)
    {
        mid = (s + e) / 2ll;
        if (s == e)
            break;
        if (k >= num(x, mid, k))
            e = mid;
        else
            s = mid + 1ll;
    }
    cout << mid << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}