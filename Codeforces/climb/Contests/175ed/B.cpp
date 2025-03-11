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
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    ll cnt = 0ll;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            v[i] = 1;
        else
            v[i] = -1;
    }
    ll repidx = -1ll;
    for (int i = 0; i < n; i++)
    {
        cnt += v[i];
        if (cnt == 0)
        {
            repidx = i + 1;
            break;
        }
    }
    ll reachidx = -1;
    cnt = x;
    for (int i = 0; i < n; i++)
    {
        cnt += v[i];
        if (cnt == 0)
        {
            reachidx = i + 1;
            break;
        }
    }

    if (reachidx == -1)
    {
        cout << 0 << '\n';
        return;
    }
    else if (repidx == -1)
    {
        cout << 1 << '\n';
        return;
    }
    else
    {
        // cout << reachidx << ' ' << repidx << '\n';
        cout << 1ll + (k - reachidx) / repidx << '\n';
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