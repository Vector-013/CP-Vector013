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
    for (auto &x : s)
        cin >> x;
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            if (s[i][j] == 'A')
            {
                sx = i, sy = j;
                s[i][j] = '.';
            }
            if (s[i][j] == 'B')
            {
                ex = i, ey = j;
                s[i][j] = '.';
            }
        }
    }
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
    q.push({sx, sy});
    p[sx][sy] = {sx, sy};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (x == ex && y == ey)
        {
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
                    p[x + i][y] = {x, y};
                    q.push({x + i, y});
                }
            }
            if (y + i >= 0 && y + i < m && s[x][y + i] == '.')
            {
                if (p[x][y + i] == make_pair(-1, -1))
                {
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