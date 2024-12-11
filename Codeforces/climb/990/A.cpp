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
    vector<int> a(n);
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        int x = sqrt(sum);
        if (x * x == sum && x & 1)
        {
            ans++;
        }
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