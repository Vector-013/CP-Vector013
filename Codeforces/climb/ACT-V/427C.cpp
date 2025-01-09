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
    int n, q, c;
    cin >> n >> q >> c;
    int a[12][111][111] = {};
    for (int i = 0; i < n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        a[c][x][y]++;
    }
    for (int k = 0; k <= c; k++)
        for (int x = 1; x < 111; x++)
            for (int y = 1; y < 111; y++)
                a[k][x][y] += a[k][x - 1][y] + a[k][x][y - 1] - a[k][x - 1][y - 1];

    while (q--)
    {
        int t, x, y, xx, yy;
        cin >> t >> x >> y >> xx >> yy;
        t %= (c + 1);
        int ans = 0;
        for (int k = 0; k <= c; k++)
        {
            int cur = a[k][xx][yy] - a[k][xx][y - 1] - a[k][x - 1][yy] + a[k][x - 1][y - 1];
            ans += ((t + k) % (c + 1)) * cur;
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;

    solve();
}