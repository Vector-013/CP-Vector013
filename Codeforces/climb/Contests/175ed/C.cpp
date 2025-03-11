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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v(n);
    ll maxp = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        maxp = max(maxp, v[i]);
    }

    ll l = 0;
    ll r = maxp;

    while (l < r)
    {
        // cout<<'p';
        ll m = (l + r) / 2;
        ll cnt = 0;
        char col = 'R';
        for (int i = 0; i < n; i++)
        {
            if (v[i] > m && s[i] == 'B' && col == 'R')
            {
                cnt++;
            }
            if(v[i]>m)
                col = s[i];
        }
        // if (col == 'R')
        //     cnt--;
        // cout << m << ' ' << cnt << '\n';
        if (cnt > k)
            l = m + 1;
        else
            r = m;
    }
    cout << l << '\n';
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