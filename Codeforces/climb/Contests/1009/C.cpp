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
    int x;
    cin >> x;
    for (int b = 0; b < 30; b++)
    {
        int y = (1 << b) - 1;
        int z = x ^ y;
        if (y < x && z < x + y && y < x + z && x < y + z)
        {
            cout << y << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}