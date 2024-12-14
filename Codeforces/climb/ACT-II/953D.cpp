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
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n), pre(n, 0), maxi(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            a[i] += c;
        pre[i] = a[i] + (i > 0 ? pre[i - 1] : 0);
    }
    maxi[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxi[i] = max(maxi[i + 1], a[i + 1]);
    vector<bool> ahed(n, false);
    for (int i = 0; i < n; i++)
        ahed[i] = (maxi[i] > pre[i]);

    int curmaxi = max_element(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n; i++)
    {
        if (i == curmaxi)
        {
            cout << 0 << " ";
            continue;
        }
        cout << i + ahed[i] << " ";
    }
    cout << '\n';
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