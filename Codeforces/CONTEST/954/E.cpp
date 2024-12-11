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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> v;
    map<ll, ll> mp;
    map<ll, ll> mp2;
    ll a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        mp[a % k]++;
        if (mp[a % k] == 1)
        {
            mp2[a % k] = v.size();
            vector<ll> temp;
            temp.push_back(a);
            v.push_back(temp);
        }
        else
        {
            v[mp2[a % k]].push_back(a);
        }
    }
    ll ans = 0ll;
    int bcnt = 0;
    if (n != 1)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].size() % 2)
            {
                bcnt++;
                if (bcnt > 1)
                    break;
            }
            sort(v[i].begin(), v[i].end());
            for (int j = 0; j < v[i].size(); j += 2)
            {
                ans += ((v[i][j + 1] - v[i][j]) / k);
            }
        }
    }
    cout << ans << '\n';
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