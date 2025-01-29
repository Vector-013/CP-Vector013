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
    for (auto &x : a)
        cin >> x;
    vector<int> suf(n), ans, q;
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = min(suf[i + 1], a[i]);
    for (int i = 0; i < n; i++)
        (a[i] == suf[i]) ? ans.push_back(a[i]) : q.push_back(a[i] + 1);
    int z = ans.size();
    int m = q.size();
    if (m)
    {
        sort(q.begin(), q.end());
        for (int i = 0; i < z; i++)
            ans[i] = (ans[i] > q[0]) ? ans[i]+1 : ans[i];
        for (int i = 0; i < m; i++)
            ans.push_back(q[i]);
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    cout << '\n';
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