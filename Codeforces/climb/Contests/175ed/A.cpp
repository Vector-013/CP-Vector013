#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> parent(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            cin >> parent[i];
        }

        vector<int> depth(n + 1, 0);
        depth[1] = 0;
        int maxDepth = 0;
        for (int i = 2; i <= n; i++)
        {
            depth[i] = depth[parent[i]] + 1;
            maxDepth = max(maxDepth, depth[i]);
        }

        vector<vector<int>> levels(maxDepth + 1);
        for (int i = 1; i <= n; i++)
        {
            levels[depth[i]].push_back(i);
        }

        vector<long long> dp(n + 1, 0);
        dp[1] = 1;

        vector<long long> S(maxDepth + 1, 0);
        S[0] = 1;

        for (int d = 1; d <= maxDepth; d++)
        {
            long long sumLevel = 0;
            for (int v : levels[d])
            {
                int par = parent[v];
                if (par == 1)
                {
                    dp[v] = S[d - 1] % MOD;
                }
                else
                {
                    dp[v] = (S[d - 1] - dp[par] + MOD) % MOD;
                }
                sumLevel = (sumLevel + dp[v]) % MOD;
            }
            S[d] = sumLevel;
        }

        long long ans = 0;
        for (int d = 0; d <= maxDepth; d++)
        {
            ans = (ans + S[d]) % MOD;
        }

        cout << ans % MOD << "\n";
    }

    return 0;
}