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
    int a, b, d, e;
    cin >> a >> b >> d >> e;
    int ans = 0;
    int req = 0;
    int c = a + b;
    req = 1;
    if (d == c + b)
        req++;
    if (e == c + d)
        req++;
    ans = max(ans, req);
    c = d - b;
    req = 1;
    if (c == a + b)
        req++;
    if (e == c + d)
        req++;
    ans = max(ans, req);
    c = e-d;
    req = 1;
    if (c == a + b)
        req++;
    if (d == c + b)
        req++;
    ans = max(ans, req);

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