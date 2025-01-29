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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto solver = [&]()
    {
        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + a[i];
        vector<ll> ans(n, n + 1);
        ll k = 1;
        for (int i = 0; i < n - 1; i++)
        {
            while (k < n && a[i + 1] == a[k])
                k++;

            ll r = upper_bound(pre.begin() + i + 1, pre.end(), pre[i + 1] + a[i]) - pre.begin();

            r = max(r, k + 1);
            if (r <= n)
                ans[i] = r - i - 1;
            if (a[i + 1] > a[i])
                ans[i] = 1;
        }
        return ans;
    };

    auto ans1 = solver();
    reverse(a.begin(), a.end());
    auto ans2 = solver();
    for (int i = 0; i < n; i++)
    {
        ll res = min(ans1[i], ans2[n - 1 - i]);
        if (res > n)
            res = -1;
        cout << res << " \n"[i == n - 1];
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
