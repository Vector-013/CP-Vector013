#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<ull> a(n);
    array<ull, 2> cnt = {0, 0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x % 2;
    }
    vector<ull> dp(4, 0ull); // 00 - 0, 01 - 1, 10 - 2, 11 - 3
    ull ans = 0ull;
    auto initdp = [&](ull x, ull y)
    {
        if (x + y == 2)
            dp[3]++;
        else if ((x + y == 1) && (x == 0))
            dp[1]++;
        else if (x + y == 0)
            dp[0]++;
        else
            dp[2]++;
    };
    ans = (a[0] + a[1] + a[2]) % 2 == 0;
    initdp(a[0], a[1]);
    initdp(a[1], a[2]);
    initdp(a[0], a[2]);
    if (a[0] + a[1] + a[2] == 0)
        dp[0]++;
    else if (a[0] + a[1] + a[2] == 2)
    {
        if (a[0] == 0)
            dp[3]++;
        else if (a[1] == 0)
            dp[1]++;
        else
            dp[2]++;
    }
    auto modadd = [&](ull a, ull b) -> ull
    {
        ull t = a + b;
        t %= mod;
        return t;
    };
    for (int i = 0; i <= 2; i++)
        cnt[a[i]]++;
    for (int i = 3; i < n; i++)
    {
        if (a[i])
        {
            ull t = modadd(dp[1], dp[2]);
            ans = modadd(ans, t);
            dp[3] = modadd(dp[3], dp[1]);
            dp[1] = modadd(dp[1], dp[2]);
            ans %= mod;
            dp[1] = modadd(dp[1], cnt[0]);
            dp[3] = modadd(dp[3], cnt[1]);
            cnt[1]++;
        }
        else
        {
            dp[2] = modadd(dp[2], dp[3]);
            ans = modadd(ans, modadd(dp[0], dp[3]));
            ans %= mod;
            ull t = modadd(dp[0], cnt[0]);
            dp[0] = modadd(dp[0], t);
            dp[2] = modadd(dp[2], cnt[1]);
            cnt[0]++;
        }
        for (auto x : dp)
            x = x % mod;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}
