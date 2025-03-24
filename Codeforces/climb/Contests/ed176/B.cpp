#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    if (k == 1)
    {
        int ans = a[0] + a[n - 1];
        for (int i = 1; i < n - 1; i++)
            ans = max(ans, a[i] + max(a[0], a[n - 1]));
        cout << ans << '\n';
        return;
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans = accumulate(a.begin(), a.begin() + k + 1, 0LL);
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}