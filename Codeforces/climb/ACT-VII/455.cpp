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
    vector<char> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    if (c[n - 1] == 'f')
    {
        cout << "0\n";
        return;
    }
    int cntf = 0;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0ll));
    for (int i = 0; i <= n; i++)
        dp[n][i] = 1;

    for (int i = n - 1; i > 0; i--)
    {
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}
