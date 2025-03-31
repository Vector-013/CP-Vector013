#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector binom(k + 1, vector<mint>(k + 1));
    for (int i = 0; i <= k; i++)
    {
        binom[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
        }
    }
    vector dp(n + 1, vector<mint>(k + 1));
    mint ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<mint> pw(k + 1); // pw[j] = (a[i])^j
        pw[0] = 1;
        for (int j = 0; j < k; j++)
        {
            pw[j + 1] = pw[j] * a[i];
        }
        dp[i][0] += 1;
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; j + l <= k; l++)
            {
                dp[i + 1][j + l] += dp[i][j] * binom[k - j][l] * pw[l];
            }
        }
        ans += dp[i + 1][k];
    }
    cout << ans.val() << endl;
}
