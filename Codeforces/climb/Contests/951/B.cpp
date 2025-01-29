
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
    int x, y;
    cin >> x >> y;

    for (int i = 0; i < 30; ++i)
    {
        if((x&(1<<i)) != (y&(1<<i)))
        {
            cout << (1<<i) << '\n';
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