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
    cin >> v[0];
    ll lcmm = v[0];
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        lcmm = lcmm * v[i] / __gcd(lcmm, (ll)v[i]);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += (lcmm / v[i]);
    if (sum >= lcmm)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; ++i)
        cout << lcmm / v[i] << " \n"[i == n - 1];
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