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
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (auto &x : a)
    {
        cin >> x;
        cnt[x]++;
    }
    sort(a.begin(), a.end());
    set<ll> s(a.begin(), a.end());
    int maxi = a[n - 1];
    int mini = a[0];
    vector<ll> dp(maxi + 1, 0);
    dp[0] = 0;
    dp[mini] = mini * cnt[mini];

    for (int i = mini + 1; i <= maxi; i++)
    {
        if (s.find(i) == s.end())
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        }
    }
    cout << dp[maxi] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}