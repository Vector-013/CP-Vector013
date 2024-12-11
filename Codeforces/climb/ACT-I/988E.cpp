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
    int n;
    cin >> n;
    auto query = [](int l, int r) -> int
    {
        cout << "? " << l << ' ' << r << endl;
        cout.flush();
        int x;
        cin >> x;
        return x;
    };
    int a = query(1, n);
    if (!a)
    {
        cout << "! IMPOSSIBLE" << endl;
        cout.flush();
        return;
    }
    bool got = false;
    int x;
    string s = string(n, ' ');
    for (int i = 2; i <= n; i++)
    {
        int b = query(1, i);
        if (b && !got)
        {
            got = true;
            s = string(i - 1 - b, '1') + string(b, '0') + "1" + string(n - i, 'n');
            x = b;
        }
        else if (got)
        {
            cout.flush();
            if (b == x)
                s[i - 1] = '0';
            else
            {
                s[i - 1] = '1';
                x = b;
            }
        }
        // cout << "? " << s << endl;
        // cout.flush();
    }
    if (got)
        cout << "! " << s << endl;
    else
        cout << "! IMPOSSIBLE" << endl;
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