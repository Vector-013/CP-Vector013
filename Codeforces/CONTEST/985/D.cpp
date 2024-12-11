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
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    vector<bool> v(n + 1, false);
    int ans = 0;
    int x, y;
    vector<tuple<int, int, int>> res;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (x != 1 && y != 1)
        {
            a.push_back({x, y});
        }
        if (x == 1)
            v[y] = true;
        if (y == 1)
            v[x] = true;
    }
    for (auto [x, y] : a)
    {

        if (x != 1 && y != 1)
        {
            res.push_back({1, x, y});
            if (v[x] && v[y])
            {
                v[x] = v[y] = false;
            }
            else if (v[x])
            {
                v[x] = false;
                v[y] = true;
            }
            else if (v[y])
            {
                v[y] = false;
                v[x] = true;
            }
            else
            {
                v[x] = true;
                v[y] = true;
            }
        }
    }
    int c = -1;
    for (int i = 2; i <= n; i++)
        if (v[i])
        {
            c = i;
            break;
        }
    if (c == -1)
    {
        if (res.size())
        {
            cout << res.size() << '\n';
            for (auto [x, y, z] : res)
            {
                cout << x << " " << y << " " << z << '\n';
            }
            return;
        }
        cout << "0\n";
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!v[i])
        {
            res.push_back({1, c, i});
            c = i;
            v[i] = true;
        }
    }
    if (res.size() == 0)
    {
        cout << "0\n";
        return;
    }
    cout << res.size() << '\n';
    for (auto [x, y, z] : res)
    {
        cout << x << " " << y << " " << z << '\n';
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