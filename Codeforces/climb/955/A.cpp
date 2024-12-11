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
    int q1, q2, w1, w2;
    cin >> q1 >> w1 >> q2 >> w2;
    if (q2 > w2)
    {
        if (q2 >= w1 && w1 > q1)
        {
            cout << "NO\n";
            return;
        }
        else
        {
            cout << "YES\n";
            return;
        }
    }
    if (w2 > q2)
    {
        if (w2 >= q1 && q1 > w1)
        {
            cout << "NO\n";
            return;
        }
        else
        {
            cout << "YES\n";
            return;
        }
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