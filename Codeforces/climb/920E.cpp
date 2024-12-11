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
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa >= xb)
    {
        cout << "Draw\n";
        return;
    }
    if ((xb - xa) & 1)
    {
        int meet = (xa + xb + 1) / 2;
        int al = max(1, ya - (meet - xa));
        int ar = min(w, ya + (meet - xa));
        int bl = max(1, yb - (xb - meet));
        int br = min(w, yb + (xb - meet));
        if (bl >= al && br <= ar)
            cout << "Alice\n";
        else
            cout << "Draw\n";
    }
    else
    {
        int meet = (xa + xb) / 2;
        int al = max(1, ya - (meet - xa));
        int ar = min(w, ya + (meet - xa));
        int bl = max(1, yb - (xb - meet));
        int br = min(w, yb + (xb - meet));
        if (al >= bl && ar <= br)
            cout << "Bob\n";
        else
            cout << "Draw\n";
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