#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 998244353;
const int N = 4e5 + 5;
#define int ll

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> an(N, 0), ap(N, 0), bn(N, 0), bp(N, 0), z(N, 0), w(N, 0);
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    int sa = accumulate(a.begin(), a.end(), 0ll);
    int sb = accumulate(b.begin(), b.end(), 0ll);

    for (int i = 0; i < n; ++i)
    {
        if (abs(sa - a[i]) < N)
        {
            if (sa - a[i] < 0)
                an[a[i] - sa] = 1;
            else
                ap[sa - a[i]] = 1;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (abs(sb - b[i]) < N)
        {
            if (sb - b[i] < 0)
                bn[b[i] - sb] = 1;
            else
                bp[sb - b[i]] = 1;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i * j > N)
                break;
            if ((an[i] && bn[j]) || (ap[i] && bp[j]))
                z[i * j] = 1;
            if ((an[i] && bp[j]) || (ap[i] && bn[j]))
                w[i * j] = 1;
        }
    }

    for (int i = 0; i < q; ++i)
    {
        int x;
        cin >> x;

        if (x > 0)
            cout << (z[x] ? "Yes\n" : "No\n");
        else
            cout << (w[-x] ? "Yes\n" : "No\n");
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
