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
    vector<ll> v(n);
    ll s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i - 1];
        s += v[i - 1];
    }
    ll ans = 0;
    ll mx = *max_element(v.begin(), v.end());
    if (mx >= 2ll * (s - mx))
    {
        cout << s - mx << '\n';
        return;
    }
    else
    {
        cout << s / 3ll << '\n';
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}