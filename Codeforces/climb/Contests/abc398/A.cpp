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
    int n;
    cin >> n;
    if (n & 1)
    {
        int m = n / 2;
        string s = string(m, '-');
        cout << s << "=" << s << '\n';
    }
    else
    {
        int m = n / 2 - 1;
        string s = string(m, '-');
        cout << s << "==" << s << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}