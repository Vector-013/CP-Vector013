#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    int w, f, n;
    cin >> w >> f >> n;
    vector<int> s(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        sum += s[i];
    }
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = sum; j >= s[i]; j--)
            dp[j] = dp[j] || dp[j - s[i]];

    int ans = inf;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[i])
        {
            int tw = (i + w - 1) / w;
            int tf = (sum - i + f - 1) / f;
            ans = min(ans, max(tw, tf));
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
