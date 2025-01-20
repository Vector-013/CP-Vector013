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
    vector<string> s(n);
    queue<pair<int, int>> q2;
    vector<vector<bool>> vis2(n, vector<bool>(m, false));
    vector<vector<int>> d1(n, vector<int>(m, inf));
    queue<pair<int, int>> q;
    vector<vector<int>> d2(n, vector<int>(m, inf));
    for (auto &x : s)
        cin >> x;
    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            if (s[i][j] == 'A')
            {
                start = {i, j};
                s[i][j] = '.';
            }
            else if (s[i][j] == 'M')
            {
                s[i][j] = '.';
                vis2[i][j] = true;
                d2[i][j] = 0;
                q2.push({i, j});
            }
        }
    }

    while (!q2.empty())
    {
        auto [x, y] = q2.front();
        q2.pop();
        for (int i = -1; i <= 1; i += 2)
        {
            if (x + i >= 0 && x + i < n && s[x + i][y] == '.')
            {
                if (!vis2[x+i][y])
                {
                    d2[x+i][y] = d2[x][y] + 1;
                    q2.push({x+i, y});
                    vis2[x+i][y] = true;
                }
            }
            if (y + i >= 0 && y + i < m && s[x][y + i] == '.')
            {
                if (!vis2[x][y+i])
                {
                    d2[x][y+i] = d2[x][y] + 1;
                    q2.push({x, y+i});
                    vis2[x][y+i] = true;
                }
            }
        }
    }
    d1[start.first][start.second] = 0;
    q.push(start);
    vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, {-1, -1}));

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if ((x == n - 1 || y == m - 1 || x == 0 || y == 0) && d1[x][y] < d2[x][y])
        {
            int sx = start.first, sy = start.second;
            cout << "YES\n";
            string ans;
            while (x != sx || y != sy)
            {
                auto [px, py] = p[x][y];
                if (px == x - 1)
                    ans += 'D';
                if (px == x + 1)
                    ans += 'U';
                if (py == y - 1)
                    ans += 'R';
                if (py == y + 1)
                    ans += 'L';
                x = px, y = py;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n'
                 << ans;
            return;
        }
        for (int i = -1; i <= 1; i += 2)
        {
            if (x + i >= 0 && x + i < n && s[x + i][y] == '.')
            {
                if (p[x + i][y] == make_pair(-1, -1))
                {
                    d1[x + i][y] = d1[x][y] + 1;
                    p[x + i][y] = {x, y};
                    q.push({x + i, y});
                }
            }
            if (y + i >= 0 && y + i < m && s[x][y + i] == '.')
            {
                if (p[x][y + i] == make_pair(-1, -1))
                {
                    d1[x][y + i] = d1[x][y] + 1;
                    p[x][y + i] = {x, y};
                    q.push({x, y + i});
                }
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}