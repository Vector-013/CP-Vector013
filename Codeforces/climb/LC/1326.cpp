#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define ll long long
    int minTaps(int n, vector<int> &z)
    {
        vector<ll> dp(n + 1, (ll)1e18);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
        {
            int l = max(0, i - z[i]);
            int r = min(n, i + z[i]);
            for (int j = l; j <= r; ++j)
                dp[r] = min(dp[r], dp[j] + 1);
        }
        return (dp[n] == (ll)1e18 ? -1 : dp[n]);
    }
};

int main()
{
    Solution s;
    vector<int> ranges = {4, 0, 0, 0, 4, 0};
    int n = 5;
    cout << s.minTaps(n, ranges) << endl;
    return 0;
}