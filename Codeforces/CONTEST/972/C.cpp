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
    string s = "narek";
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> dp(5, -inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        auto ndp = dp;
        for (int j = 0; j < 5; j++)
        {
            int scr = dp[j];
            int k = j;
            for (auto c : v[i])
            {
                if (s[k] == c)
                {
                    k++;
                    if (k == 5)
                    {
                        k = 0;
                        scr += 5;
                    }
                }
                else if (s.find(c) != -1)
                {
                    scr--;
                }
            }
            ndp[k] = max(ndp[k], scr);
        }
        dp = ndp;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans = max(ans, dp[i] - i);
    }
    cout << ans << '\n';
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