#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = inf;
    for (int i = 0; i <= 100; i += a)
    {
        for (int j = 0; j <= 50; j += b)
        {
            if ((((i / a) + (2 * (j / b)) == n)))
            {
                ans = min(ans, i + j);
            }
        }
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