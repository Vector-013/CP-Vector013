#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 1e9 + 7;
vector<ll> nines = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

void solve()
{
    int n;
    cin >> n;
    if (to_string(n).find('7') != string::npos)
    {
        cout << "0\n";
        return;
    }
    auto check = [&](int r) -> bool
    {
        vector<int> d(20, 0);
        ll a = n - r;
        int len = 0, mc = 40;

        if (a)
        {
            while (a)
            {
                d[len++] = a % 10;
                a /= 10;
            }
        }
        else
            d[len++] = 0;
        int maxl = max(len, 12);

        vector<vector<int>> dp(32, vector<int>(42, 0));
        auto ndp = dp;
        dp[r][0] = 1;

        for (int i = 0; i < maxl; ++i)
        {
            for (int j = 0; j <= r; ++j)
                for (int k = 0; k < mc; ++k)
                    ndp[j][k] = 0;
            int dig = d[i] * ((i < len));
            for (int j = 0; j <= r; ++j)
            {
                for (int k = 0; k < mc; ++k)
                {
                    if (dp[j][k])
                    {
                        for (int w = 0; w <= j; ++w)
                        {
                            int nc = (dig + k + w) / 10, nm = dp[j][k], nrem = j - w;
                            int newdig = (dig + k + w) % 10;
                            if (mc > nc)
                            {
                                if (newdig == 7)
                                    nm |= 2;
                                ndp[nrem][nc] |= nm;
                            }
                        }
                    }
                }
            }
            dp = ndp;
        }

        return (dp[0][0] & 2);
    };
    for (int i = 1; i < 31; ++i)
    {
        if (check(i))
        {
            cout << i << "\n";
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
