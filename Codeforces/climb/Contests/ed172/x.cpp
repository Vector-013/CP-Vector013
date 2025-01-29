#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
#define pb push_back

bool check(vector<int> &dp, int &k, int &mid)
{

    int y = 0;
    for (int i = 0; i < mid - 1 && i < dp.size(); i++)
    {
        y += dp[i];
        if (y >= k)
            return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - '0';
        v.pb(x);
    }
    vector<int> dp;
    //  dp.pb(0);
    int z = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp.pb(z);
        if (s[i] == '1')
        {
            z += 1;
        }
        else
        {
            z -= 1;
        }
    }

    sort(dp.begin(), dp.end(), greater<int>());
    int lo = 2;
    int hi = n;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(dp, k, mid))
        {

            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
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