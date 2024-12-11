#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const pair<int, int> moves[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void solve()
{
    int n, m, lab;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> v(n * m);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'L')
            {
                lab = i * m + j;
                v[lab] = -1;
            }
            else if (s[i][j] == '.')
            {
                for (auto [dx, dy] : moves)
                {
                    int x = i + dx;
                    int y = j + dy;
                    if (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '#')
                        v[i * m + j]++;
                }
            }
        }
    }
    queue<int> q;
    q.push(lab);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        int x = f / m;
        int y = f % m;
        if (f != lab)
            s[x][y] = '+';
        for (auto [dx, dy] : moves)
        {
            int xx = x + dx;
            int yy = y + dy;
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] != '#' && v[xx * m + yy] != -1)
            {
                v[xx * m + yy]--;
                if (v[xx * m + yy] <= 1)
                {
                    v[xx * m + yy] = -1;
                    q.push(xx * m + yy);
                }
            }
        }
    }
    for (auto a : s)
        cout << a << '\n';
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
