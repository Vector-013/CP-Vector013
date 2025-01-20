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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    map<pair<int, int>, int> mp;
    bool bad = 0;

    auto mapset = [&](int u, int v, int s) -> void
    {
        if (u > v)
            swap(u, v);
        mp[{u, v}] = s;
    };
    auto mapget = [&](int u, int v) -> int
    {
        if (u > v)
            swap(u, v);
        return mp[{u, v}];
    };
    for (int i = 0; i < m; i++)
    {
        int u, v;
        string s;
        cin >> u >> v >> s;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        if (mapget(u, v) && mapget(u, v) != (s == "imposter" ? 1 : 2))
            bad = 1;
        if (s == "imposter")
            mapset(u, v, 1);
        else
            mapset(u, v, 2);
    }
    if (bad)
    {
        cout << "-1\n";
        return;
    }
    vector<int> comp(n, -1);
    int cnt = 0;
    auto dfs1 = [&](auto &self, int u) -> void
    {
        comp[u] = cnt;
        for (int v : g[u])
        {
            if (comp[v] == -1)
                self(self, v);
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (comp[i] == -1)
        {
            dfs1(dfs1, i);
            cnt++;
        }
    }
    vector<vector<int>> graphs(cnt);
    ll leftout = 0;
    for (int i = 0; i < n; i++)
    {
        graphs[comp[i]].push_back(i);
    }

    ll cnti = 0, cntc = 0;
    vector<int> status(n, -1);

    auto chk = [&](auto self, int u, int p, int stu) -> void
    {
        if (status[u] != -1)
        {
            if (status[u] != stu)
                bad = 1;
            return;
        }
        status[u] = stu;
        if (stu == 1)
            cnti++;
        else
            cntc++;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if (mapget(u, v) == 1)
                self(self, v, u, 3 - stu);
            else
                self(self, v, u, stu);
        }
    };

    ll ans = 0;

    for (auto &graf : graphs)
    {
        if (graf.size() == 1)
        {
            ans++;
            continue;
        }
        cnti = 0, cntc = 0;
        chk(chk, graf[0], -1, 1);
        ans += max(cnti, cntc);
    }
    cout << (bad ? -1 : ans) << '\n';
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