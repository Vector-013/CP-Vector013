#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> ip(2);
    cin >> ip[0] >> ip[1];
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    auto score = [&](char a, char b, char c)
    {
        int sum = (a == 'A') + (b == 'A') + (c == 'A');
        return (sum > 1);
    };

    dp[1][1] = score(ip[0][0], ip[0][1], ip[1][0]);
    dp[1][2] = score(ip[0][0], ip[1][0], ip[1][1]);

    for (int i = 3; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            int sc11 = dp[i - 3][0] + score(ip[0][i - 3], ip[0][i - 2], ip[0][i - 1]) + score(ip[1][i - 3], ip[1][i - 2], ip[1][i - 1]); //
            int sc12 = dp[i - 2][1] + score(ip[0][i - 1], ip[1][i - 1], ip[1][i - 2]);
            int sc13 = dp[i - 2][2] + score(ip[0][i - 2], ip[0][i - 1], ip[1][i - 1]);
            // cout << i << '\n';
            // cout << sc11 << " " << sc12 << " " << sc13 << endl;
            // cout << dp[i - 2][1] << endl;
            dp[i][0] = max(sc11, max(sc12, sc13));
        }

        if ((i != n) && (i % 3 == 1))
        {
            int sc21 = dp[i - 1][0] + score(ip[0][i - 1], ip[0][i], ip[1][i - 1]);
            int sc22 = dp[i - 3][1] + score(ip[0][i - 2], ip[0][i - 1], ip[0][i]) + score(ip[1][i - 3], ip[1][i - 2], ip[1][i - 1]);
            dp[i][1] = max(sc21, sc22);
            // cout << "Inside case 2" << endl;
            // cout << sc21 << " " << sc22 << endl;

            int sc31 = dp[i - 1][0] + score(ip[0][i - 1], ip[1][i], ip[1][i - 1]);
            int sc32 = dp[i - 3][2] + score(ip[0][i - 3], ip[0][i - 2], ip[0][i - 1]) + score(ip[1][i - 2], ip[1][i - 1], ip[1][i]);
            dp[i][2] = max(sc31, sc32);
        }
    }
    cout << dp[n][0] << '\n';
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