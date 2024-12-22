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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> cnt;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        cnt[b[i]]++;
    }
    int ans = 0, now = 0;
    for (int i = 0; i < n; i++)
    {
        if (--cnt[a[i]] < 0)
            now++;
        if (i >= m - 1)
        {
            if (m - k >= now)
                ans++;
            int x = a[i - m + 1];
            if (cnt[x]++ < 0)
                now--;
        }
    }
    cout << ans << "\n";
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