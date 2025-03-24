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
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int u;
        cin >> u;
        pq.emplace(u);
        if (not((n - i + 1) % (k + 1)))
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
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