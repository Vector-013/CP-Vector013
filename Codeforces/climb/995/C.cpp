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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    set<int> s;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    set<int> c;
    for (int i = 1; i <= n; i++)
    {
        if (!s.count(i))
            c.insert(i);
    }
    for (int i = 0; i < m; i++)
    {
        if (c.count(a[i]))
        {
            cout << ((c.size() == 1) ? 1 : 0);
        }
        else
        {
            cout << ((c.size() == 0) ? 1 : 0);
        }
    }
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