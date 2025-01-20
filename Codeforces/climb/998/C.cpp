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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    map<int, int> cnt;
    map<int, int> vis;
    for (auto x : a)
        cnt[x]++;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[a[i]])
        {
            vis[a[i]] = 1;
            vis[k - a[i]] = 1;
            if (a[i] != k - a[i])
                ans += min(cnt[a[i]], cnt[k - a[i]]);
            else
                ans += cnt[a[i]] / 2;
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