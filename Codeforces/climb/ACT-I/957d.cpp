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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int z = -1;
    for (int i = 0; i <= n; i++)
    {
        if (z >= 0 && s[z] == 'W')
        {
            z = i;
            k--;
        }
        if (i == n || s[i] == 'L' || i - z == m)
        {
            z = i;
        }
        if (z >= 0 && z < n && s[z] == 'C')
        {
            cout << "NO\n";
            return;
        }
    }
    cout << (k >= 0 ? "YES" : "NO") << '\n';
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