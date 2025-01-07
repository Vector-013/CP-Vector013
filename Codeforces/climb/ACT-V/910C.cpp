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
    int n, m, k;
    cin >> n >> m >> k;
    if ((k - n - m + 2 < 0) || ((k - m - n + 2 != 0) && (k - m - n + 2) % 2 != 0))
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n - 2; i++)
    {
        bool clr = 1;
        int c = m - 1;
        while (c--)
        {
            cout << (clr ? "R" : "B") << " \n"[c == 0];
            clr = !clr;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        bool clr = 1;
        int c = m - 2;
        while (c--)
        {
            cout << (clr ? "R " : "B ");
            clr = !clr;
        }
        cout << ((k & 1) ? "R\n" : "B\n");
    }
    bool clr;
    int c = m - 2;
    if ((m - 1) & 1)
        clr = 0;
    else
        clr = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int c = m;
        if (i == 0)
        {
            c = m - 2;
            cout << "B B ";
        }
        if (i == n - 2)
        {
            if ((k - n - m + 2) % 4 != 0)
                clr = !clr;
        }
        while (c--)
        {
            cout << (clr ? "R " : "B ");
        }
        clr = !clr;
        cout << '\n';
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