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
    int a, b, k;
    cin >> a >> b >> k;
    if (k % 2 == 1)
    {
        for (int i = 1; i <= k / 2; i++)
        {
            cout << 1000000 + i << " " << 1000000 + i << '\n'
                 << -1000000 - i << " " << -1000000 - i << '\n';
        }
        cout << a * k << " " << b * k << '\n';
        return;
    }
    else
    {
        for (int i = 1; i < k / 2; i++)
        {
            cout << 1000000 + i << " " << 1000000 + i << '\n'
                 << -1000000 - i << " " << -1000000 - i << '\n';
        }
        cout << a * k / 2 + 1 << " " << b * k / 2 + 1 << '\n'
             << a * k / 2 - 1 << " " << b * k / 2 - 1 << '\n';
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