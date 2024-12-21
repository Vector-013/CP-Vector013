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
    int n, q;
    cin >> n >> q;
    int d1, d2 = n - 1, v1 = n - 1, v2 = n - 1;

    for (int i = 1; i < n; i++)
        cout << i << " " << i + 1 << '\n';

    cout << '\n';

    for (int i = 0; i < q; ++i)
    {
        cin >> d1;
        if (d1 == d2)
        {
            cout << "-1 -1 -1" << '\n';
            continue;
        }
        cout << n << " " << v1 << " " << d1 << '\n';
        v1 = d1;
        d2 = d1;
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