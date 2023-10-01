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

int query(int l, int r)
{
    if (l == r)
        return 0;
    cout << "? " << l << " " << r << endl;
    int ans;
    cin >> ans;
    return ans;
}
int solver(int l, int r)
{
    if (l == r)
        return l;
    int p, q, w;
    p = (l + r) / 2;
    q = solver(l, p);
    w = solver(p + 1, r);
    if (query(l, w - 1) == query(l, w))
        return w;
    else
        return q;
}
void solve()
{
    int n;
    cin >> n;
    int ans = solver(1, n);
    cout << "! " << ans << endl;
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