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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &y : b)
        cin >> y;

    int sa = accumulate(a.begin(), a.end(), 0ll);
    int sb = accumulate(b.begin(), b.end(), 0ll);
    if (sb > sa)
    {
        cout << "-1\n";
        return;
    }
    if (sa == sb)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int mxa = *max_element(a.begin(), a.end());
        cout << ((a == b) ? mxa + 1ll : -1) << '\n';
        return;
    }

    int d = sa - sb;
    vector<int> pos;
    int mxa = *max_element(a.begin(), a.end());
    int mxb = *max_element(b.begin(), b.end());
    for (int i = 1; i * i <= d; i++)
    {
        if (d % i == 0)
        {
            if (i > mxb && i <= mxa)
                pos.push_back(i);
            if (d / i != i && d / i > mxb && d / i <= mxa)
                pos.push_back(d / i);
        }
    }

    for (auto x : pos)
    {
        vector<int> c;
        for (int i = 0; i < n; i++)
            c.push_back(a[i] % x);
        sort(c.begin(), c.end());
        sort(b.begin(), b.end());
        if (c == b)
        {
            cout << x << '\n';
            return;
        }
    }
    cout << "-1\n";
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