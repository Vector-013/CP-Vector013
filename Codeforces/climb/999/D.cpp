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
    vector<ll> a(n), b(m);
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    s1 = accumulate(a.begin(), a.end(), 0ll);
    s2 = accumulate(b.begin(), b.end(), 0ll);
    if (s1 != s2)
    {
        cout << "NO\n";
        return;
    }
    priority_queue<ll> pq;
    map<ll, ll> mp;
    for (int i = 0; i < m; i++)
        pq.push(b[i]);
    for (auto x : a)
        mp[x]++;

    bool x = 1;
    for (int i = 0; i < 2 * n - m; i++)
    {
        if (pq.empty())
        {
            x = 0;
            break;
        }
        ll t = pq.top();
        pq.pop();
        if (mp[t])
        {
            mp[t]--;
            continue;
        }
        pq.push(t / 2ll);
        pq.push((t + 1ll) / 2ll);
    }
    cout << ((x && pq.empty()) ? "YES\n" : "NO\n");
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