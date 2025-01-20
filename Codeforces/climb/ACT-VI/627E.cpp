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
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        for (int j = 0; j <= i; j++)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + ((s - j) % h >= l && (s - j) % h <= r));
            if (j < n)
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + ((s - j - 1) % h >= l && (s - j - 1) % h <= r));
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}