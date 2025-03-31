#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jobScheduling(vector<int> &st, vector<int> &et, vector<int> &pr)
    {
        int n = st.size();
        vector<vector<int>> job;
        for (int i = 0; i < n; ++i)
            job.push_back({st[i], et[i], pr[i]});

        sort(job.begin(), job.end());
        for (int i = 0; i < n; ++i)
            st[i] = job[i][0];
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int cp = 0;
            int ni = lower_bound(st.begin(), st.end(), job[i][1]) - st.begin();
            cp = job[i][2] + dp[ni] * (ni != n);
            dp[i] = max(cp, dp[i + 1]);
        }
        return dp[0];
    }
};

int main()
{
    Solution s;
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};
    cout << s.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}