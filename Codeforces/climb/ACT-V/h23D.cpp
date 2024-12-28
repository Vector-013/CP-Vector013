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
    m--;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    ll s = 0, ans = 0;
    priority_queue<int> pq;
    priority_queue<int> pq2;

    for (int i = m; i > 0; i--)
    {
        s += v[i];
        pq.push(v[i]);
        while (s > 0)
        {
            ll x = pq.top();
            pq.pop();
            s -= 2 * x;
            ans++;
        }
    }
    s = 0;
    for (int i = m + 1; i < n; i++)
    {
        s += v[i];
        pq2.push(-v[i]);
        while (s < 0)
        {
            ll x = pq2.top();
            pq2.pop();
            s += 2 * x;
            ans++;
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