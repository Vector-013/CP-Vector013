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
    vector<int> dp{0}, cnt{0};              // dp[i] = max checks passed with i intellect
    int z = 0;
    for (auto &x : a)
    {
        if (x > 0)
        {
            if (x < cnt.size())             // any intelect greater than this will pass at least these many chks, there fore added to the suffix of the dp
                cnt[x]++;
        }
        else if (x < 0)
        {
            if (z + x >= 0)
            {
                cnt[0]++;
                cnt[z + x + 1]--;       // strength is less, hence in the prefix of the array
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
                dp[i] = max(dp[i], dp[i - 1]);          // setting dp[i] to max of dp[i] dp[i-1] such that in next iteration of numbers, we can compare old dp and new dp.
            }                                           // as in as we just saw a zero and dont know what to do with it, on base we set dp[i] to max of dp[i] and dp[i-1]
        }
    }
    dp[0] += cnt[0];
    for (int i = 1; i < cnt.size(); i++)
    {
        cnt[i] += cnt[i - 1];
        dp[i] += cnt[i];
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}