#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> f(n, vector<int>(4, -1)); // B-0     R-1     G-2     Y-3
    vector<vector<int>> b(n, vector<int>(4, -1));
    vector<string> z(n);
    for (int i = 0; i < n; i++)
        cin >> z[i];

    int ib = -1, ir = -1, ig = -1, iy = -1;
    for (int i = 0; i < n; i++)
    {
        if (z[i][0] + z[i][1] == ('B' + 'R'))
        {
            ib = i;
            ir = i;
        }
        if (z[i][0] + z[i][1] == ('G' + 'R'))
        {
            ig = i;
            ir = i;
        }
        if (z[i][0] + z[i][1] == ('Y' + 'R'))
        {
            iy = i;
            ir = i;
        }
        if (z[i][0] + z[i][1] == ('G' + 'Y'))
        {
            iy = i;
            ig = i;
        }
        if (z[i][0] + z[i][1] == ('G' + 'B'))
        {
            ib = i;
            ig = i;
        }
        if (z[i][0] + z[i][1] == ('Y' + 'B'))
        {
            ib = i;
            iy = i;
        }
        f[i][0] = ib;
        f[i][1] = ir;
        f[i][1] = ig;
        f[i][1] = iy;
    }
    ib = -1, ir = -1, ig = -1, iy = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (z[i][0] + z[i][1] == ('B' + 'R'))
        {
            ib = i;
            ir = i;
        }
        if (z[i][0] + z[i][1] == ('G' + 'R'))
        {
            ig = i;
            ir = i;
        }
        if (z[i][0] + z[i][1] == ('Y' + 'R'))
        {
            iy = i;
            ir = i;
        }
        if (z[i][0] + z[i][1] == ('G' + 'Y'))
        {
            iy = i;
            ig = i;
        }
        if (z[i][0] + z[i][1] == ('G' + 'B'))
        {
            ib = i;
            ig = i;
        }
        if (z[i][0] + z[i][1] == ('Y' + 'B'))
        {
            ib = i;
            iy = i;
        }
        b[i][0] = ib;
        b[i][1] = ir;
        b[i][1] = ig;
        b[i][1] = iy;
    }

    int x, y;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        if (z[x] == z[y])
        {
            cout << abs(x - y) << '\n';
            continue;
        }
        if ((z[x][0] == z[y][0]) || (z[x][0] == z[y][1]) || (z[x][1] == z[y][0]) || (z[x][1] == z[y][1]))
        {
            cout << abs(x - y) << '\n';
            continue;
        }
        if ((z[x] == "BR") && z[y] == "GY")
        {
            if ((b[x][2] < y) || (b[x][3] < y) || (f[y][0] > x) || (f[y][1] > x))
            {
                cout << abs(x - y) << '\n';
                continue;
            }
            else
            {
                int jj = min(b[x][2], min(b[x][3], min(f[y][0], f[y][1])));
                cout << abs(x - y) << min(abs(jj - x), abs(jj - y)) << '\n';
                continue;
            }
        }
        if ((z[x] == "BG") && z[y] == "RY")
        {
            if ((b[x][1] < y) || (b[x][3] < y) || (f[y][0] > x) || (f[y][2] > x))
            {
                cout << abs(x - y) << '\n';
                continue;
            }
            else
            {
                int jj = min(b[x][1], min(b[x][3], min(f[y][0], f[y][2])));
                cout << abs(x - y) << min(abs(jj - x), abs(jj - y)) << '\n';
                continue;
            }
        }
        if ((z[x] == "BY") && z[y] == "GR")
        {
            if ((b[x][1] < y) || (b[x][2] < y) || (f[y][0] > x) || (f[y][3] > x))
            {
                cout << abs(x - y) << '\n';
                continue;
            }
            else
            {
                int jj = min(b[x][1], min(b[x][2], min(f[y][0], f[y][3])));
                cout << abs(x - y) << min(abs(jj - x), abs(jj - y)) << '\n';
                continue;
            }
        }
        swap(x, y);
        if (z[x] == z[y])
        {
            cout << abs(x - y) << '\n';
            continue;
        }
        if ((z[x][0] == z[y][0]) || (z[x][0] == z[y][1]) || (z[x][1] == z[y][0]) || (z[x][1] == z[y][1]))
        {
            cout << abs(x - y) << '\n';
            continue;
        }
        if ((z[x] == "BR") && z[y] == "GY")
        {
            if ((b[x][2] < y) || (b[x][3] < y) || (f[y][0] > x) || (f[y][1] > x))
            {
                cout << abs(x - y) << '\n';
                continue;
            }
            else
            {
                int jj = min(b[x][2], min(b[x][3], min(f[y][0], f[y][1])));
                cout << abs(x - y) << min(abs(jj - x), abs(jj - y)) << '\n';
                continue;
            }
        }
        if ((z[x] == "BG") && z[y] == "RY")
        {
            if ((b[x][1] < y) || (b[x][3] < y) || (f[y][0] > x) || (f[y][2] > x))
            {
                cout << abs(x - y) << '\n';
                continue;
            }
            else
            {
                int jj = min(b[x][1], min(b[x][3], min(f[y][0], f[y][2])));
                cout << abs(x - y) << min(abs(jj - x), abs(jj - y)) << '\n';
                continue;
            }
        }
        if ((z[x] == "BY") && z[y] == "GR")
        {
            if ((b[x][1] < y) || (b[x][2] < y) || (f[y][0] > x) || (f[y][3] > x))
            {
                cout << abs(x - y) << '\n';
                continue;
            }
            else
            {
                int jj = min(b[x][1], min(b[x][2], min(f[y][0], f[y][3])));
                cout << abs(x - y) << min(abs(jj - x), abs(jj - y)) << '\n';
                continue;
            }
        }
    }
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