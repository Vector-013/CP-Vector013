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
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    if (n == 1)
    {
        cout << a[0] << '\n';
        return;
    }
    ll ans = 0, sum = 0;
    ans = accumulate(a.begin(), a.end(), 0ll);

    for (int i = 0; a.size() > 1 && i < n; i++)
    {
        vector<ll> b;
        for (int i = 1; i < a.size(); i++)
            b.push_back(a[i] - a[i - 1]);
        a = b;
        sum = accumulate(a.begin(), a.end(), 0ll);
        ans = max(ans, abs(sum));
    }
    ans = max(ans, abs(a[0]));
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
};
