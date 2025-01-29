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
    string s;
    cin >> n >> s;
    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            if (x == -1)
                x = i;
            y = i;
        }
    }
    if (x == -1)
    {
        cout << 0 << '\n';
        return;
    }
    cout << (y - x + 1) << '\n';
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