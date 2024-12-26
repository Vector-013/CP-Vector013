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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(n, 0);
    vector<vector<bool>> mark(n, vector<bool>(n, 1));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            a[j]--;
            for (int l = 0; l < j; l++)
                mark[a[j]][a[l]] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (mark[a[j]][a[i]])
                dp[a[i]] = max(dp[a[i]], dp[a[j]]);
        ans = max(ans, ++dp[a[i]]);
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}