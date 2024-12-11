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
    int n;
    cin >> n;
    if (n == 1 || n == 3)
    {
        cout << -1 << '\n';
        return;
    }
    if (n % 2 == 0)
    {
        cout << string(n - 2, '3') << "66\n";
        return;
    }
    else
    {
        cout << string(n - 4, '3') << "6366\n";
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