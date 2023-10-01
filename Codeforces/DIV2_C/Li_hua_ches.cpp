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

int query(int r, int c)
{
    int dist;
    cout << "? " << r << " " << c << endl;
    cin >> dist;
    return dist;
}
void solve()
{
    int n, m, d2, d3;
    cin >> n >> m;
    int d1 = query(1, 1);
    if (d1 == 0)
    {
        cout << "! " << 1 << " " << 1 << endl;
        return;
    }
    int r1 = min(d1 + 1, n);
    int c1 = min(d1 + 1, m);
    d2 = query(r1, c1);
    if (d2 == 0)
    {
        cout << "! " << r1 << " " << c1 << endl;
        return;
    }
    d3 = query(r1, c1 - d2);
    if (d3 == 0)
    {
        cout << "! " << r1 << " " << c1 - d2 << endl;
        return;
    }
    else
    {
        cout << "! " << r1 - d2 << " " << c1 << endl;
        return;
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