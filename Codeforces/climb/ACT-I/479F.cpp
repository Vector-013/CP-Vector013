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
    map<int, int> dp;
    cin >> n;
    int ans = -1, cur;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
        if (dp[a[i]] > ans)
        {
            ans = dp[a[i]];
            cur = a[i];
        }
    }
    cout << ans << '\n';
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == cur)
        {
            res.push_back(i + 1);
            cur--;
        }
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}