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
    vector<int> p(2 * n);
    for (int i = 0; i < 2 * n;i++)
        cin >> p[i];
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < 2 * n;)
    {
        int j = i;
        while (j < 2 * n && p[j] <= p[i])
            j++;
        int cnt = j - i;
        for (int k = n; k >= cnt; k--)
            dp[k] |= dp[k - cnt];
        i = j;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
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