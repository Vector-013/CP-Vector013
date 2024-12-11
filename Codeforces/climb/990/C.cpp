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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
        cin >> b[i];

    ll g = -1;
    ll q = -linf;
    ll fans = -linf;
    auto a1 = a;
    auto b1 = b;
    for (int g = 0; g < n; g++)
    {
        q = a1[g] + b1[g];
        a1.erase(a1.begin() + g);
        b1.erase(b1.begin() + g);
        ll ans = q;
        for (int i = 0; i < n - 1; i++)
        {
            ans += max(a1[i], b1[i]);
        }
        fans = max(fans, ans);
        a1 = a;
        b1 = b;
    }
    cout << fans << '\n';
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