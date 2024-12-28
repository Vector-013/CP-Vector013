#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int cur = 0;
    int idx = 0;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        for (; idx < m && v[idx].first <= i; ++idx)
        {
            pq.push(v[idx].second);
            last = max(last, v[idx].second);
            cur++;
        }
        while (!pq.empty() && pq.top() <= i)
        {
            pq.pop();
            cur--;
        }
        if (cur > 0)
            dp[last] = max(dp[last], dp[i] + cur);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    cout << dp[n] << '\n';
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