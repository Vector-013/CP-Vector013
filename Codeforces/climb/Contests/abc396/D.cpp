#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef long long ll;

struct Edge
{
    int to;
    ll weight;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<bool> vis(n + 1, false);
    vector<ll> path_weights;
    ll minx = LLONG_MAX;

    auto finder = [&](auto &self, int src, int dest, ll curx)
    {
        if (src == dest)
        {
            minx = min(minx, curx);
            return;
        }

        vis[src] = true;

        for (Edge &edge : g[src])
        {
            int next = edge.to;
            if (!vis[next])
            {
                self(self, next, dest, curx ^ edge.weight);
            }
        }
        vis[src] = false;
    };

    finder(finder, 1, n, 0ll);

    cout << minx << '\n';
}
