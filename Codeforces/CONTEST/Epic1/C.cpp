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

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> dp(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    long long ans = v[n - 1];
    dp[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > dp[i + 1])
            dp[i] = v[i];
        else
            dp[i] = dp[i + 1] + 1;
        ans = max(ans, dp[i]);
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