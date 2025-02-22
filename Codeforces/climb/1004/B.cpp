#include <iostream>
#include <algorithm>
using namespace std;

bool contains7(long long x)
{
    while (x > 0)
    {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}

bool possibleWithOps(long long n, int r)
{
    long long A = n - r;
    int digits[20] = {0};
    int len = 0;
    if (A == 0)
    {
        digits[len++] = 0;
    }
    else
    {
        while (A > 0)
        {
            digits[len++] = A % 10;
            A /= 10;
        }
    }

    int L = max(len, 12);
    const int maxCarry = 40;
    int dp[32][42] = {0}, next_dp[32][42] = {0};
    dp[r][0] = 1;

    for (int pos = 0; pos < L; pos++)
    {
        for (int i = 0; i <= r; i++)
            for (int j = 0; j < maxCarry; j++)
                next_dp[i][j] = 0;

        int d = (pos < len ? digits[pos] : 0);

        for (int rem = 0; rem <= r; rem++)
        {
            for (int carry = 0; carry < maxCarry; carry++)
            {
                int mask = dp[rem][carry];
                if (mask == 0)
                    continue;
                for (int add = 0; add <= rem; add++)
                {
                    int total = d + carry + add;
                    int new_digit = total % 10;
                    int new_carry = total / 10;
                    if (new_carry >= maxCarry)
                        continue;

                    int new_rem = rem - add;
                    int new_mask = mask;
                    if (new_digit == 7)
                        new_mask |= 2;

                    next_dp[new_rem][new_carry] |= new_mask;
                }
            }
        }

        for (int i = 0; i <= r; i++)
            for (int j = 0; j < maxCarry; j++)
                dp[i][j] = next_dp[i][j];
    }

    return (dp[0][0] & 2) != 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (contains7(n))
        {
            cout << 0 << "\n";
            continue;
        }

        int ans = -1;
        for (int r = 1; r <= 30; r++)
        {
            if (possibleWithOps(n, r))
            {
                ans = r;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
