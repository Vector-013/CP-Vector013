#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp{0}, cnt{0};
    int z = 0;
    for (auto &x : a)
    {
        if (x > 0)
        {
            if (x < cnt.size())
                cnt[x]++;
        }
        else if (x < 0)
        {
            if (z + x >= 0)
            {
                cnt[0]++;
                cnt[z + x + 1]--;
            }
        }
        else
        {
            dp[0] += cnt[0];
            for (int i = 1; i < cnt.size(); i++)
            {
                cnt[i] += cnt[i - 1];
                dp[i] += cnt[i];
            }
            z++;
            dp.push_back(0);
            cnt.assign(z + 1, 0);
            for (int i = z; i > 0; i--)
            {
                dp[i] = max(dp[i], dp[i - 1]);
            }
        }
    }
    dp[0] += cnt[0];
    for (int i = 1; i < cnt.size(); i++)
    {
        cnt[i] += cnt[i - 1];
        dp[i] += cnt[i];
    }
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}