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
    int k;
    cin >> k;
    int ans = 1;
    if (n > k && m > k)
    {
        cout << k * k << '\n';
        return;
    }
    if (n > k && m <= k)
    {
        cout << k * m << '\n';
        return;
    }
    if (m > k && n <= k)
    {
        cout << k * n << '\n';
        return;
    }
    if (m <= k && n <= k)
    {
        cout << m * n << '\n';
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