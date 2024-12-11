auto djikstra = [&](ll s)
    // {
    //     vector<ll> d(2 * n, linf);
    //     priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    //     pq.emplace(0ll, 2 * s);

    //     while (!pq.empty())
    //     {
    //         auto [l, u] = pq.top();
    //         pq.top();

    //         if (d[u] != linf)
    //             continue;

    //         d[u] = l;
    //         int hh = u % 2;
    //         int v = u / 2;

    //         if (!hh && hrs[v])
    //         {
    //             pq.emplace(l, 2 * v + 1);
    //         }
    //         for (auto [x, y] : g[v])
    //         {
    //             pq.emplace(y + (hh ? w / 2 : w), 2 * x + hh);
    //         }
    //     }
    //     vector<ll> z(n, inf);
    //     for (int i = 0; i < n; i++)
    //     {
    //         z[i] = min(d[2 * i], d[2 * i + 1]);
    //     }
    //     return z;
    // };

    // auto v1 = djikstra(0ll);
    // auto vn = djikstra(n - 1);
    // ll ans = linf;
    // for (int i = 0; i < n; i++)
    // {
    //     ans = min(ans, max(v1[i], vn[i]));
    // }
    // if (ans == linf)
    // {
    //     ans = -1;
    // }