#include <bits/stdc++.h>
using namespace std;
typedef long long l;
using i64 = long long;
typedef unsigned long long ul;
typedef long double ld;
const int inf = 2e9;
const l linf = 9e18;
const int mod = 998244353;
#define int long long

void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    vector<pair<int, int>> v1, v2;

    auto divide = [&](int l, int r, vector<pair<int, int>> &v) -> void
    {
        while (l != r)
        {
            int i = 0ll;
            while ((l % (1ll<<(i+1)) == 0ll) and ((l + (1ll<<(i+1))) <= r))
                i++;
            v.push_back({l, l + (1ll << i)});
            l += (1ll << i);                   
        } };
    divide(l1, r1, v1);
    divide(l2, r2, v2);
    // for(auto [x, y]: v1)cout << x << ' ' << y << '\n';
    // for(auto [x, y]: v2)cout << x << ' ' << y << '\n';
    int ans = 0;
    for (auto [x1, x2] : v1)
    {
        for (auto [y1, y2] : v2)
        {
            int x = x2 - x1, y = y2 - y1;
            if (x < y)
                swap(x, y);
            ans += x / y;
        }
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
}