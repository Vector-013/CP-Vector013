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
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = dp[i] + 20;
        dp[i + 1] = min(dp[i + 1], dp[lower_bound(t.begin(), t.end(), t[i] - 89) - t.begin()] + 50);
        dp[i + 1] = min(dp[i + 1], dp[lower_bound(t.begin(), t.end(), t[i] - 1439) - t.begin()] + 120);
        cout << dp[i + 1] - dp[i] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;

    solve();
}