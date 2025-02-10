#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int totcnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        totcnt += count(s[i].begin(), s[i].end(), '.');
    }
    totcnt = m * n - totcnt;

    auto reflect = [&](int x, int y, int direc, char c) -> tuple<int, int, int>
    {
        if (c == '.')
        {
            if (direc == 0)
                return {x, y + 1, 0};
            if (direc == 1)
                return {x + 1, y, 1};
            if (direc == 2)
                return {x, y - 1, 2};
            if (direc == 3)
                return {x - 1, y, 3};
        }
        if (c == '/')
        {
            if (direc == 0)
                return {x - 1, y, 3};
            if (direc == 1)
                return {x, y - 1, 2};
            if (direc == 2)
                return {x + 1, y, 1};
            if (direc == 3)
                return {x, y + 1, 0};
        }
        else
        {
            if (direc == 0)
                return {x + 1, y, 1};
            if (direc == 1)
                return {x, y + 1, 0};
            if (direc == 2)
                return {x - 1, y, 3};
            if (direc == 3)
                return {x, y - 1, 2};
        }
        return {x, y, direc};
    };

    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4, 0)));
    vector<vector<int>> path(n, vector<int>(m, 0));

    auto travel = [&](int sx, int sy, int direc) -> bool
    {
        vis[sx][sy][direc] = 1;
        int cnt = (s[sx][sy] != '.');
        path[sx][sy] = 1;
        while (true)
        {
            auto [nx, ny, nd] = reflect(sx, sy, direc, s[sx][sy]);
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                if (cnt == totcnt)
                    return true;
                return false;
            }
            if (vis[nx][ny][nd])
            {
                return false;
            }
            if (s[nx][ny] != '.' && !path[nx][ny])
                cnt++;
            sx = nx, sy = ny, direc = nd;
            vis[sx][sy][direc] = 1;
            path[sx][sy] = 1;
        }
        return false;
    };

    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        if (travel(i, 0, 0))
        {
            ans.push_back("W" + to_string(i + 1));
        }
        vis.assign(n, vector<vector<int>>(m, vector<int>(4, 0)));
        path.assign(n, vector<int>(m, 0));
        if (travel(i, m - 1, 2))
        {
            ans.push_back("E" + to_string(i + 1));
        }
        vis.assign(n, vector<vector<int>>(m, vector<int>(4, 0)));
        path.assign(n, vector<int>(m, 0));
    }
    for (int i = 0; i < m; i++)
    {
        if (travel(0, i, 1))
        {
            ans.push_back("N" + to_string(i + 1));
        }
        vis.assign(n, vector<vector<int>>(m, vector<int>(4, 0)));
        path.assign(n, vector<int>(m, 0));
        if (travel(n - 1, i, 3))
        {
            ans.push_back("S" + to_string(i + 1));
        }
        vis.assign(n, vector<vector<int>>(m, vector<int>(4, 0)));
        path.assign(n, vector<int>(m, 0));
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}
