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
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n), v(k);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> v[i];

    int cur = 0;
    for (int j = 0; j < n; j++)
        cur += (a[j] == j + 1);
    int ans = cur + (d - 1) / 2;
    for (int i = 0; i < min(2 * n, d) - 1; ++i)
    {
        int c = v[i % k];
        for (int j = 0; j < c; j++)
            a[j]++;
        int cur = 0;
        for (int j = 0; j < n; j++)
            cur += (a[j] == j + 1);
        ans = max(ans, cur + (d - i - 2) / 2);
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