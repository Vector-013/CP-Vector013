#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define lp long long
bool inbox(lp n, lp x, lp y)
{
    if (x > 0 && y > 0 && x <= n && y <= n)
        return true;
    return false;
}
bool noton(lp n, lp x, lp y)
{
    if (x > 0 && y > 0 && x < n && y <= n)
        return true;
    return false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    lp n;
    std::cin >> n;
    lp dp[n + 1];
    dp[1] = 0;
    if (n == 1)
    {
        std::cout << 0;
        return 0;
    }
    for (lp i = 2; i <= n; i++)
    {
        lp cnt = 0;
        for (int j = 1; j <= i; j++)
        {
            if (inbox(i, i - 2, j + 1))
                cnt++;
            if (inbox(i, i - 2, j - 1))
                cnt++;
            if (inbox(i, i - 1, j + 2))
                cnt++;
            if (inbox(i, i - 1, j - 2))
                cnt++;
        }
        for (int j = 1; j < i; j++)
        {
            if (noton(i, j - 1, i - 2))
                cnt++;
            if (noton(i, j + 1, i - 2))
                cnt++;
            if (noton(i, j - 2, i - 1))
                cnt++;
            if (noton(i, j + 2, i - 1))
                cnt++;
        }
        dp[i] = dp[i - 1] + cnt;
    }
    for (lp i = 1; i <= n; i++)
        std::cout << (i * i * (i * i - 1ll) / 2ll) - dp[i] << '\n';
}