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
ll min(ll a, ll b)
{
    if (a <= b)
        return a;
    else
        return b;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;
        a[v[i]] = i;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((v[i] == i) || (a[i] == v[i]))
            continue;

        int x = v[v[i]];
        int y = v[a[i]];
        swap(v[v[i]], v[a[i]]);
        a[x] = a[y];
        a[y] = i;
        ans++;

    }
    cout << ans << '\n';
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