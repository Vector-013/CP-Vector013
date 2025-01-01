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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    for (int i = 0; i < x; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 1; i < x; ++i)
    {
        if (a[i] - a[i - 1] == 2)
            ans++;
    }
    ans += (a[x - 1] == n - 1 && a[0] == 1) || (a[x - 1] == n && a[0] == 2);
    while (x > 2)
    {
        if (x == 3)
        {
            ans++;
            break;
        }
        if (x == 4)
        {
            ans += 2;
            break;
        }
        ans += x / 2;
        x = (x + 1) / 2;
    }
    cout << ans << '\n';
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