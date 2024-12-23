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
    ll l, r, i, k;
    cin >> l >> r >> i >> k;
    if (i == 0)
    {
        cout << 0 << '\n';
        return;
    }

    auto rxor = [](ll l, ll r) -> ll
    {
        if (l == 0)
            l++;
        auto f = [](ll x) -> ll
        {
            if (x % 4 == 0)
                return x;
            if (x % 4 == 1)
                return 1;
            if (x % 4 == 2)
                return x + 1;
            return 0;
        };
        return f(r) ^ f(l - 1);
    };
    ll res1 = rxor(l, r);

    if (l == r)
    {
        if (l % (1 << i) == k)
            l = 0;
        cout << l << '\n';
        return;
    }

    if (r < (1 << i))
    {
        if (k >= l && k <= r)
        {
            cout << (res1 ^ k) << '\n';
            return;
        }
        cout << res1 << '\n';
        return;
    }
    ll num2 = r;
    if (r % (1 << i) >= k)
    {
        num2 -= r % (1 << i) - k;
    }
    else
    {
        num2 = r - r % (1 << i) - (1 << i) + k;
    }
    ll num1 = l;
    if (l <= (1 << i))
    {
        if (k >= l)
            num1 = k;
        else
            num1 = (1 << i) + k;
    }
    else
    {
        if (l % (1 << i) <= k)
            num1 = l + k - l % (1 << i);
        else
            num1 = l + (1 << i) - l % (1 << i) + k;
    }
    // cout << num1 << ' ' << num2 << '\n';
    ll l1 = num1 >> i;
    ll l2 = num2 >> i;
    bool b = (l2 - l1 + 1) % 2;
    ll res2 = rxor(l1, l2);
    // cout << res1 << ' ' << res2 << '\n';
    if (b)
        res2 = (res2 << i) + k;
    else
        res2 = (res2 << i);
    cout << (res1 ^ res2) << '\n';
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