#include <iostream>
using namespace std;
typedef long long ll;
void solve()
{
    int a, b, c, d, ans = 0;
    cin >> a >> b >> c >> d;
    if (a == 0)
        cout << 1 << '\n';
    else
    {
        ans = a + 2 * min(b, c) + min(a + 1, d + max(b, c) - min(b, c));
        cout << ans << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}