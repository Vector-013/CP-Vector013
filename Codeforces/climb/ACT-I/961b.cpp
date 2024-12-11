#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    i64 m;
    std::cin >> n >> m;

    std::map<int, int> f;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        f[a[i]] = c;
    }

    i64 ans = 0;
    for (auto [x, y] : f)
    {
        ans = std::max(ans, 1LL * x * std::min<i64>(y, m / x));
        if (f.contains(x + 1))
        {
            int z = f[x + 1];
            i64 c;
            if (1LL * x * y >= m)
            {
                c = m / x;
            }
            else
            {
                c = y + std::min<i64>(z, (m - 1LL * x * y) / (x + 1));
            }
            ans = std::max(ans, std::min(m, c * x + std::min<i64>(c, z)));
        }
    }
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
