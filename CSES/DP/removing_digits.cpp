#include <iostream>
using namespace std;
int in(int a, int b)
{
    int ans = (a < b) ? a : b;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    int dig, mini = (int)1e9;
    for (int i = 1; i <= n; i++)
    {
        int cpy = i;
        mini = (int)1e9;
        while (cpy)
        {
            dig = cpy % 10;
            cpy /= 10;
            if (i >= dig && dig != 0)
            {
                mini = in(mini, dp[i - dig] + 1);
            }
        }
        dp[i] = mini;
    }
    cout << dp[n] << '\n';
}