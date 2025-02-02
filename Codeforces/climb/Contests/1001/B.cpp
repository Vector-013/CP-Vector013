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
    int n;
    cin >> n;
    bool f = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x <= 2 * max(i - 1, n - i))
            f = 0;
    }
    cout << (f ? "YES" : "NO") << '\n';
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