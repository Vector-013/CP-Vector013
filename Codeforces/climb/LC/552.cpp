#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int checkRecord(int n)
    {
        vector<long long> dp(6, 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 0;
        dp[4] = 0;
        dp[5] = 0;
        int mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i)
        {
            auto ndp = dp;
            ndp[0] = (dp[0] + dp[2] + dp[3]) % mod;
            ndp[1] = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4] + dp[5]) % mod;
            ndp[2] = dp[0];
            ndp[3] = dp[2];
            ndp[4] = dp[1];
            ndp[5] = dp[4];
            dp = ndp;
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % mod;
    }
};

int main()
{
    Solution a;
    cout << a.checkRecord(1) << "\n";
    cout << a.checkRecord(2) << "\n";
    cout << a.checkRecord(10101) << "\n";
    return 0;
}