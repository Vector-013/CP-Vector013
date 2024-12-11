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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto score = [&](int q, int w, int e, int r) -> int
    {
        return (a[q] == a[w]) + (a[e] == a[r]);
    };

    if (n & 1)
    {
        ll ans = score(n / 2 - 1, n / 2, n / 2 + 1, n / 2);
        for (int i = n / 2 - 2; i >= 0; i--)
        {
            ll n1 = a[i + 1], n2 = a[n - i - 2];
            if ((n1 == a[i]) || (n2 == a[n - i - 1]))
            {
                swap(a[i], a[n - i - 1]);
                // cout << a[i] << " " << a[n - i - 1] << '\n';
            }
            ans += score(i, i + 1, n - i - 2, n - i - 1);
        }
        cout << ans << '\n';
    }
    else
    {
        ll ans = (a[n / 2] == a[n / 2 - 1]);
        for (int i = n / 2 - 2; i >= 0; i--)
        {
            ll n1 = a[i + 1], n2 = a[n - i - 2];
            if ((n1 == a[i]) || (n2 == a[n - i - 1]))
            {
                swap(a[i], a[n - i - 1]);
            }
            ans += score(i, i + 1, n - i - 2, n - i - 1);
        }
        cout << ans << '\n';
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