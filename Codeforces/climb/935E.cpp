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
    int n, x, loc;
    cin >> n >> x;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] == x)
            loc = i;
    }
    auto z = v;
    sort(z.begin(), z.end());
    auto c = z;
    reverse(c.begin(), c.end());
    if (v == z || v == c)
    {
        cout << "0\n";
        return;
    }
    int l = 1, r = n + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (v[m] <= x)
            l = m;
        else
            r = m;
    }
    cout << "1\n";
    cout << l << " " << loc << '\n';
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