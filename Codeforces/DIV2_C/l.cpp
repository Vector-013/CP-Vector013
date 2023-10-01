#include <bits/stdc++.h>

using i64 = long long;

int query(int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    std::cout << "? " << l << " " << r << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

int solve(int l, int r)
{
    if (l == r)
    {
        return l;
    }
    int m = (l + r) / 2;
    int x = solve(l, m);
    int y = solve(m + 1, r);

    if (query(l, y - 1) == query(l, y))
    {
        return y;
    }
    else
    {
        return x;
    }
}

void solve()
{
    int n;
    std::cin >> n;

    int ans = solve(1, n);
    std::cout << "! " << ans << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
