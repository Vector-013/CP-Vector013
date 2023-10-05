#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ll n, dif, a = 0;
    cin >> n;
    vector<ll> v(n), sum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        a += v[i];
        sum[i] = a;
    }
    vector<vector<ll>> dp;
    dp.assign(n, vector<ll>(n, 0));
    for (int j = 0; j < n; j++)
    {
        dp[j][j] = v[j];
        for (int i = j - 1; i >= 0; i--)
        {
            dif = sum[j] - sum[i] + v[i];
            dp[i][j] = dif - min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << '\n';
}
