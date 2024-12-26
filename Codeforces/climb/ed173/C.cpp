#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

void solve()
{
    ll n;
    set<ll> ans;
    cin >> n;
    vector<ll> v(n);
    vector<ll> pref(n + 1, 0);
    ll nfi = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1 || v[i] == -1)
            continue;
        nfi = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != nfi)
            pref[i + 1] = pref[i] + v[i];
        else
            pref[i + 1] = 0;
    }
    if (nfi == -1)
    {
        ll x1 = 0, x2 = 0, zz = -linf, xx = linf;
        for (int i = 1; i <= n; i++)
        {
            x1 = max(x1, pref[i]);
            x2 = min(x2, pref[i]);
            zz = max(zz, pref[i] - x2);
            xx = min(xx, pref[i] - x1);
        }
        for (int i = xx; i <= zz; i++)
            ans.insert(i);
    }
    else
    {
        ll x1 = 0, x2 = 0, zz = -linf, xx = linf;
        for (int i = 1; i <= nfi; i++)
        {
            x1 = max(x1, pref[i]);
            x2 = min(x2, pref[i]);
            zz = max(zz, pref[i] - x2);
            xx = min(xx, pref[i] - x1);
        }
        for (int i = xx; i <= zz; i++)
            ans.insert(i);

        ll n1 = pref[nfi] - x2, m1 = pref[nfi] - x1;

        x1 = 0, x2 = 0, zz = -linf, xx = linf;
        for (int i = nfi + 2; i <= n; ++i)
        {
            x1 = max(x1, pref[i]);
            x2 = min(x2, pref[i]);
            zz = max(zz, pref[i] - x2);
            xx = min(xx, pref[i] - x1);
        }
        for (int i = xx; i <= zz; i++)
            ans.insert(i);

        ll n2 = x1, m2 = x2;
        ll low = m1 + m2, high = n1 + n2;
        for (ll i = low; i <= high; i++)
            ans.insert(i + v[nfi]);
    }
    if (n == 1 && v[0] != 1 && v[0] != -1)
        ans.insert(0);
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << " ";
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