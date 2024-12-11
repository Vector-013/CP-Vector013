#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    ll n, z = 0;
    string s;
    cin >> n;
    cin >> s;

    ll ans = 1ll * n * (n + 1) / 2ll;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1' && i >= (z + 1))
        {
            ans -= (i + 1);
            z++;
        }
        else
        {
            if (z >= 1)
                z--;
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