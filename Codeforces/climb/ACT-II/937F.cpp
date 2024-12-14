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
    int a, b, c;
    cin >> a >> b >> c;
    if (a + 1 != c)
    {
        cout << "-1\n";
        return;
    }
    ll cur = (int)ceil(log2(c));
    ll nxt = 1 << cur;
    int left = nxt - c;
    if (left >= b)
    {
        cout << cur << '\n';
        return;
    }
    b -= left;
    cur++;
    left = c;
    // cout << cur << ' ' << nxt << ' ' << left << '\n';
    while (b)
    {
        if (left >= b)
        {
            cout << cur << '\n';
            return;
        }
        b -= left;
        cur++;
    }
    if (b == 0)
    {
        cout << cur << '\n';
        return;
    }
    else
    {
        cout << "-1\n";
        return;
    }
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