#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    ll x, y;
    cin >> x >> y;
    vector<vector<vector<pair<ll, bool>>>> dp(61, vector<vector<pair<ll, bool>>>(2, vector<pair<ll, bool>>(2, {-1, false})));

    dp[60][0][0] = {0, true};

    for (int bit = 59; bit >= 0; bit--)
    {
        for (int cx = 0; cx <= 1; cx++)
        {
            for (int cy = 0; cy <= 1; cy++)
            {
                int bx = (x >> bit) & 1;
                int by = (y >> bit) & 1;

                int nbx = (bx + cx) % 2;
                int nby = (by + cy) % 2;
                int ncx = (bx + cx) / 2;
                int ncy = (by + cy) / 2;

                if (!(nbx == 1 && nby == 1) && dp[bit + 1][ncx][ncy].second)
                    dp[bit][cx][cy] = {dp[bit + 1][ncx][ncy].first, true};

                nbx = (bx + 1 + cx) % 2;
                nby = (by + 1 + cy) % 2;
                ncx = (bx + 1 + cx) / 2;
                ncy = (by + 1 + cy) / 2;

                if (!(nbx == 1 && nby == 1) && dp[bit + 1][ncx][ncy].second)
                {
                    int z = dp[bit + 1][ncx][ncy].first | (1LL << bit);

                    if (dp[bit][cx][cy].second)
                        dp[bit][cx][cy].first = min(dp[bit][cx][cy].first, z);
                    else
                        dp[bit][cx][cy] = {z, true};
                }
            }
        }
    }

    cout << ((dp[0][0][0].second) ? dp[0][0][0].first : -1) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}