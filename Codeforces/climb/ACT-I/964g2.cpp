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
    int x;
    int l = 1, r = 999;
    while (r - l > 2)
    {
        int a = (2 * l + r) / 3;
        int b = (2 * r + l) / 3;
        cout << "? " << a << ' ' << b << endl;
        cout.flush();
        cin >> x;
        if (x == a * b)
        {
            l = b;
        }
        else if (x == a * (b + 1))
        {
            l = a;
            r = b;
        }
        else
        {
            r = a;
        }
    }
    if (r - l == 2)
    {
        cout << "? 1 " << l + 1 << endl;
        int x;
        cin >> x;

        if (x == l + 1)
        {
            l = l + 1;
        }
        else
        {
            r = l + 1;
        }
    }
    cout << "! " << r << endl;
    cout.flush();
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