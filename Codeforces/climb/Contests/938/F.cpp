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
    int a[4];
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
        ans += a[i] / 2;
    }
    ans += ((a[0] & 1) && (a[1] & 1) && (a[2] & 1));
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