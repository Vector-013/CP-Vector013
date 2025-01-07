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
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i];
    int q;
    cin >> q;
    vector<int> x(q);
    for (int i = 0; i < q; i++)
        cin >> x[i];

    vector<int> a(n, 0);
    auto chk = [&](int q) -> bool
    {
        auto tmp = a;
        for (int i = 0; i < q; i++)
        {
            tmp[x[i] - 1] = 1;
        }
        vector<int> pre(n + 1, 0);
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + tmp[i - 1];
        for (int i = 0; i < m; i++)
        {
            if ((pre[r[i]] - pre[l[i] - 1]) > (r[i] - l[i] + 1) / 2)
                return true;
        }
        return false;
    };
    if (!chk(q))
    {
        cout << -1 << '\n';
        return;
    }
    int ll = 0, rr = q;
    while (rr - ll > 1)
    {
        int mid = (ll + rr) / 2;
        if (chk(mid))
            rr = mid;
        else
            ll = mid;
    }
    cout << ll + 1 << '\n';
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