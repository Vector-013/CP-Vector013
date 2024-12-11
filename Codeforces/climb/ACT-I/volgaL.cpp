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
    int ans = 0;
    int a = n, b = n, c = n;
    ans = n / 2 + (n % 2);
    if (n % 2)
    {
        b -= 1;
        ans += b / 2 + (b % 2);
        c -= b / 2 + (b % 2);
        ans += c / 3 + (c % 3 != 0);
    }
    else
    {
        ans += b / 2 + (n % 2);
        c -= b / 2 + (n % 2);
        ans += c / 3 + (c % 3 != 0);
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
        solve();
}