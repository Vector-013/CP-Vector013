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
    int x, y, k;
    cin >> x >> y >> k;
    if (x < y)
    {
        cout << "0 0 " << x << " " << x << '\n';
        cout << x << " " << 0 << " " << 0 << " " << x << '\n';
        return;
    }
    else
    {
        cout << "0 0 " << y << " " << y << '\n';
        cout << y << " " << 0 << " " << 0 << " " << y << '\n';
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