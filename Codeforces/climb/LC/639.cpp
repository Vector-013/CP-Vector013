#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1ll;
        if (s[0] == '0')
            return 0;
        if (s[0] == '*')
            dp[1] = 9ll;
        else
            dp[1] = 1ll;

        for (int i = 2; i <= n; ++i)
        {
            if (s[i - 1] == '0')
            {
                if (s[i - 2] == '1' || s[i - 2] == '2')
                    dp[i] = dp[i - 2];
                else if (s[i - 2] == '*')
                    dp[i] = (2ll * dp[i - 2]) % mod;
                else
                    return 0;
            }
            else
            {
                if (s[i - 2] == '0' and s[i - 1] != '*')
                    dp[i] = dp[i - 1];
                else if ((s[i - 2] == '1' and s[i - 1] >= '1' and s[i - 1] <= '9') or (s[i - 2] == '2' and s[i - 1] <= '6' and s[i - 1] >= '1'))
                    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
                else if (s[i - 2] == '2' and s[i - 1] > '6')
                    dp[i] = dp[i - 1];
                else if (s[i - 2] == '*' and s[i - 1] >= '1' and s[i - 1] <= '9')
                    dp[i] = (dp[i - 1] + (s[i - 1] <= '6' ? 2ll : 1ll) * dp[i - 2]) % mod;
                else if (s[i - 1] == '*')
                {
                    if (s[i - 2] == '*')
                        dp[i] = (9ll * dp[i - 1] + 15 * dp[i - 2]) % mod;
                    else if (s[i - 2] == '0')
                        dp[i] = (9ll * dp[i - 1]) % mod;
                    else if (s[i - 2] == '1')
                        dp[i] = (9ll * dp[i - 1] + dp[i - 2] * 9ll) % mod;
                    else if (s[i - 2] == '2')
                        dp[i] = (9ll * dp[i - 1] + 6ll * dp[i - 2]) % mod;
                    else
                        dp[i] = (9ll * dp[i - 1]) % mod;
                }
                else
                    dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.numDecodings("**") << endl;
    return 0;
}