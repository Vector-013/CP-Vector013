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
    int q, w, e, r;
    cin >> q >> w >> e >> r;
    int a = 0;
    if (q == e)
        a++;
    if (w == r)
        a++;
    int z = 0;
    for (int i = min(q, w); i <= max(e, r); i++)
    {
        if (i >= q && i <= w && i >= e && i <= r)
            z++;
    }
    cout << z + 1 - a << '\n';
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