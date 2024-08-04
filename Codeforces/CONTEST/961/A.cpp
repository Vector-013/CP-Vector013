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
    int n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << 0 << '\n';
        return;
    }

    if (n >= m)
    {
        cout << 1 << "\n";
        return;
    }
    int q = n;
    int s = n;
    for (int i = 2; i < 2 * n; i++)
    {
        if (i % 2 == 0)
        {
            q--;
        }
        s += q;
        if (s >= m)
        {
            cout << i << '\n';
            return;
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