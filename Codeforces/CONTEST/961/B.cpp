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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    vector<pair<ll, ll>> a;
    ll cur = v[0];
    ll curcnt = 1;
    if (v.size() == 1)
    {
        a.push_back({v[0], 1});
    }
    for (ll i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
            curcnt++;
        else
        {
            a.push_back({v[i - 1], curcnt});
            curcnt = 1;
        }
        if (i == v.size() - 1)
            a.push_back({v[i], curcnt});
    }
    ll maxi = -linf;
    ll mod;
    if (a.size() == 1)
    {
        mod = m % a[0].first;
        if (a[0].first * a[0].second <= m)
        {
            cout << a[0].first * a[0].second << '\n';
            return;
        }
        cout << m - mod << '\n';
        return;
    }
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i].first << " " << a[i].second << '\n';
    // }
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i - 1].first - a[i].first == 1)
        {
            if (a[i - 1].first * a[i - 1].second + a[i].first * a[i].second < m)
            {
                maxi = max(a[i - 1].first * a[i - 1].second + a[i].first * a[i].second, maxi);
            }
            else if (a[i - 1].first * a[i - 1].second + a[i].first * a[i].second == m)
            {
                cout << m << '\n';
                return;
            }
            else
            {
                a[i].first *(a[i].second + a[i - 1].second);
                mod = m % a[i].first;
                if (a[i - 1].second >= mod)
                {
                    cout << m << '\n';
                    return;
                }
                maxi = max(maxi, a[i].first * (a[i].second + a[i - 1].second) + a[i - 1].second);
            }
        }
        mod = m % a[i - 1].first;
        if (a[i - 1].first * a[i - 1].second <= m)
        {
            maxi = max(maxi, a[i - 1].first * a[i - 1].second);
        }
        else if (a[i - 1].first * a[i - 1].second > m)
        {
            maxi = max(maxi, m - mod);
        }
        else
        {
            maxi = max(maxi, a[i - 1].first * a[i - 1].second);
        }
    }
    int i = a.size();
    mod = m % a[i - 1].first;
    if (a[i - 1].first * a[i - 1].second <= m)
    {
        maxi = max(maxi, a[i - 1].first * a[i - 1].second);
    }
    else if (a[i - 1].first * a[i - 1].second > m)
    {
        maxi = max(maxi, m - mod);
    }
    else
    {
        maxi = max(maxi, a[i - 1].first * a[i - 1].second);
    }
    cout << maxi << '\n';
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