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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + m + 1);
    auto b = a;
    vector<bool> t(n + m + 1, 0);
    int cntp = 0, cntt = 0;
    int bad = -1, rsn = 0;
    for (int i = 0; i <= n + m; ++i)
        cin >> a[i];
    ll ans = 0;
    bool done = 0;
    for (int i = 0; i < n + m; ++i)
    {
        cin >> b[i];
        if (bad == -1 && (cntp == n || cntt == m))
            bad = -2;
        if (bad != -1)
        {
            if (cntp == n)
            {
                cntt++;
                rsn = 0;
                ans += b[i];
                t[i] = 1;
                if (!done && a[i] > b[i])
                {
                    bad = i;
                    done = 1;
                }
            }
            else
            {
                rsn = 1;
                ans += a[i];
                cntp++;
                if (!done && a[i] < b[i])
                {
                    bad = i;
                    done = 1;
                }
            }
            continue;
        }
        if (a[i] > b[i])
        {
            cntp++;
            ans += a[i];
        }
        else
        {
            cntt++;
            ans += b[i];
            t[i] = 1;
        }
    }
    cin >> b[n + m];
    vector<vector<ll>> v(2, vector<ll>(n + m + 1, -linf));
    v[0] = a;
    v[1] = b;
    if (bad != -2)
    {
        for (int i = 0; i < n + m; i++)
        {
            ll tmp = ans;
            tmp -= v[t[i]][i];
            tmp += v[rsn ^ 1][n + m];
            if (i < bad)
            {
                if (t[i] == rsn)
                {
                    tmp += v[rsn][bad];
                    tmp -= v[rsn ^ 1][bad];
                }
            }
            cout << tmp << " ";
        }
    }
    else
    {
        for (int i = 0; i < n + m; i++)
        {
            ll tmp = ans;
            tmp -= v[t[i]][i];
            tmp += v[t[i]][n + m];
            cout << tmp << " ";
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