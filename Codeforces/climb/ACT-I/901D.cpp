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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        (a[i] < n) ? mp[a[i]]++ : a[i] = a[i];
    }
    sort(a.begin(), a.end());
    int curmex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == curmex)
            curmex++;
    }
    vector<int> dp(n + 1, inf);
    dp[curmex] = 0;
    for (int i = curmex; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            dp[j] = min(dp[j], dp[i] + i * mp[j] + j - i);
        }
    }
    cout << dp[0] << '\n';
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