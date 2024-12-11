#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    vector<int> pre(n, -1), suf(n, n);
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        pre[i] = max(a[i], pre[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = min(a[i], suf[i + 1]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << pre[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < n; i++)
    // {
    //     cout << suf[i] << ' ';
    // }
    // cout << '\n';

    vector<int> ans(n, -1);
    for (int i = 1, j = 0; i <= n; i++)
    {
        if (i == n || !(suf[i] < pre[i - 1]))
        {
            for (int k = j; k < i; k++)
                ans[k] = pre[i - 1];
            j = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
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