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
    vector<int> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);

    for (int i = 1; i < n; ++i)
    {
        auto req = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]);
        if (req != b.end())
        {
            if (a[i] < a[i - 1])
                a[i] = *req - a[i];
            else
                a[i] = min(a[i], *req - a[i]);
        }
        if (a[i] < a[i - 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
