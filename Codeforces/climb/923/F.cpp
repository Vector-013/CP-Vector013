#include <bits/stdc++.h>
#define eb push_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))
#define fo(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
using namespace std;
typedef long long ll;
#define endl '\n'
typedef pair<int, int> ii;

vector<vector<int>> g;
vector<vector<int>> f;
vector<int> id;
vector<int> vis;
int ans;

void dfs(int src, int i)
{
    vis[src] = 1;
    id[src] = i;
    for (int x : g[src])
    {
        if (!vis[x])
            dfs(x, i);
    }
    return;
}

void dfs_n(int src)
{
    vis[src] = 1;
    for (int x : f[src])
    {
        if (!vis[x])
        {
            if (id[x] == id[src])
                dfs_n(x);
            else
                ans++;
        }
    }
    return;
}

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    ans = 0;
    g.resize(n);
    f.resize(n);

    fo(i, 0, n)
    {
        g[i].clear();
        f[i].clear();
    }

    fo(i, 0, m1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        f[a].eb(b);
        f[b].eb(a);
    }

    fo(i, 0, m2)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].eb(b);
        g[b].eb(a);
    }

    vis.assign(n, 0);
    id.assign(n, -1);
    int gcomp = 0;

    fo(i, 0, n)
    {
        if (!vis[i])
        {
            dfs(i, i);
            gcomp++;
        }
    }

    vis.assign(n, 0);
    int fcomp = 0;

    fo(i, 0, n)
    {
        if (!vis[i])
        {
            dfs_n(i);
            fcomp++;
        }
    }

    ans += fcomp - gcomp;
    cout << ans << endl;

    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}