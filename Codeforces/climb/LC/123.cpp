#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(5, 0);
        dp[0] = -prices[0];
        dp[1] = INT_MIN;
        dp[2] = INT_MIN;
        dp[3] = INT_MIN;
        dp[4] = 0;

        for (int i = 1; i < n; ++i)
        {
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[3] = max(dp[3], dp[2] + prices[i]);
            dp[4] = max(dp[4], dp[3]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution s;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}