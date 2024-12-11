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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    string t = s;
    int x = 0, y = 0;
    for (int i = 0; i < 20; i++)
        t += s;

    auto check = [&](int x, int y)
    {
        if (x == a && y == b)
            return true;
        return false;
    };

    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] == 'N')
        {
            y++;
            if (check(x, y))
            {
                cout << "YES\n";
                return;
            }
        }
        else if (t[i] == 'S')
        {
            y--;
            if (check(x, y))
            {
                cout << "YES\n";
                return;
            }
        }
        else if (t[i] == 'E')
        {
            x++;
            if (check(x, y))
            {
                cout << "YES\n";
                return;
            }
        }
        else if (t[i] == 'W')
        {
            x--;
            if (check(x, y))
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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