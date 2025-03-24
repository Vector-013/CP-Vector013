#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto z = s;
    reverse(z.begin(), z.end());
    if (s == string(n, s[0]))
    {
        cout << "NO\n";
        return;
    }
    if (k == 0 and s >= z)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}