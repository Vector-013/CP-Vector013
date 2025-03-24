#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> adj(N * K);
    for (int i = 0; i < N * K - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](auto &&self, int x, int p = -1) -> int
    {
        int sum = 0;
        int cnt = 0;
        for (auto y : adj[x])
        {
            if (y == p)
            {
                continue;
            }
            int t = self(self, y, x);
            if (t == -1)
            {
                return -1;
            }
            if (t > 0)
            {
                cnt++;
                sum += t;
            }
        }

        if (cnt > 2)
        {
            return -1;
        }
        if (sum == K - 1)
        {
            return 0;
        }
        else if (cnt == 2)
        {
            return -1;
        }
        else
        {
            return sum + 1;
        }
    };
    if (dfs(dfs, 0) == 0)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}