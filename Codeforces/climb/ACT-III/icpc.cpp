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
    int n;
    cin >> n;
    vector<int> v(n);
    int loc1 = -1, loc2 = -1;
    int cnt1, cnt2, cnt3, cnt4;
    cnt1 = cnt2 = cnt3 = cnt4 = 0;
    vector<int> z, w;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        string s = s1 + " " + s2;
        if (s == "set true")
        {
            v[i] = 1;
            loc1 = i;
            cnt1++;
        }
        if (s == "set false")
        {
            v[i] = 2;
            cnt2++;
            z.push_back(i);
        }
        if (s == "unset true")
        {
            v[i] = 3;
            loc2 = i;
            cnt3++;
        }
        if (s == "unset false")
        {
            v[i] = 0;
            cnt4++;
            w.push_back(i);
        }
    }
    if (loc1 == -1 && loc2 != -1)
    {
        cout << "-1\n";
        return;
    }
    bool sane = true;
    int q;
    cin >> q;
    if (cnt2)
        sane = false;
    vector<vector<int>> dag(n);
    vector<bool> vis(n, false);
    vector<bool> for_root(n, true);
    vector<vector<int>> edges;
    if (loc1 == -1)
    {
        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            edges.push_back({x, y});
            for_root[y] = false;
        }
        if (!sane)
        {
            cout << "-1\n";
            return;
        }
    }
    else if (loc2 == -1)
    {
        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            edges.push_back({x, y});
            for_root[y] = false;
        }
        for (auto x : w)
        {
            edges.push_back({x, loc1});
        }
        for (auto x : z)
        {
            edges.push_back({loc1, x});
        }
    }
    else
    {
        vector<bool> done(n, false);
        edges.push_back({loc1, loc2});
        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            edges.push_back({x, y});
            for_root[y] = false;
            done[x] = true;
            done[y] = true;
            if (v[x] == 0 && v[y] == 2)
            {
                edges.push_back({x, loc1});
            }
            if (v[x] == 2 && v[y] == 0)
            {
                edges.push_back({loc2, y});
            }
            if (v[x] == 0 && v[y] == 3)
            {
                edges.push_back({x, loc1});
            }
            if (v[x] == 1 && v[y] == 0)
            {
                edges.push_back({loc2, y});
            }
        }
        for (auto x : z)
        {
            edges.push_back({loc1, x});
            edges.push_back({x, loc2});
            done[x] = true;
            done[loc1] = true;
            done[loc2] = true;
        }
        for (auto x : w)
        {
            if (!done[x])
            {
                edges.push_back({loc2, x});
                done[x] = true;
                done[loc2] = true;
            }
        }
    }

    auto checkDAG = [&]
    {
        vector<vector<int>> dag(n);
        for (const auto &edge : edges)
            dag[edge[0]].push_back(edge[1]);

        vector<bool> vis(n, false);
        vector<bool> rec(n, false);
        stack<int> topo;

        auto dfs = [&](auto &self, int u) -> bool
        {
            vis[u] = true;
            rec[u] = true;
            for (auto v : dag[u])
            {
                if (!vis[v])
                {
                    if (self(self, v))
                        return true;
                }
                else if (rec[v])
                    return true;
            }
            rec[u] = false;
            topo.push(u);
            return false;
        };
        if (loc1 != -1)
        {
            if (dfs(dfs, loc1))
            {
                cout << "-1\n";
                return;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (dfs(dfs, i))
                {
                    cout << "-1\n";
                    return;
                }
            }
        }
        while (!topo.empty())
        {
            cout << topo.top() + 1 << " ";
            topo.pop();
        }
        cout << "\n";
    };

    checkDAG();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}