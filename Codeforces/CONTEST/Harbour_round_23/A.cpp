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
    int x, y, n;
    cin >> x >> y >> n;
    if (y - x < (n * (n - 1) / 2))
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> v(n);
    v[0] = x;
    v[n - 1] = y;
    int dif = 1;
    for (int i = n - 2; i > 0; i--)
    {
        v[i] = v[i + 1] - dif;
        dif++;
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << '\n';
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