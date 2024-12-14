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
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    priority_queue<ll> pq;
    ll ans = 0;
    ll scr = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            ans++;
            scr += a[i];
        }
        else
        {
            if (scr + a[i] >= 0)
            {
                ans++;
                scr += a[i];
                pq.push(-a[i]);
            }
            else if (!pq.empty() && -a[i] < pq.top())
            {
                scr += a[i] + pq.top();
                pq.pop();
                pq.push(-a[i]);
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
        solve();
}