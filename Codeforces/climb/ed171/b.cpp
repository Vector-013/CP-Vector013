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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll k = -1;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if (n % 2)
    {
        k = linf;
        ll tmp = -1;
        auto b = a;
        for (int i = 0; i < n; i++)
        {
            tmp = -1;
            b = a;
            b.erase(b.begin() + i);
            // cout << b.size() << '\n';
            for (int j = 1; j < b.size(); j += 2)
            {
                tmp = max(tmp, b[j] - b[j - 1]);
            }
            k = min(k, tmp);
        }
    }
    else
    {
        for (int i = 1; i < n; i += 2)
        {
            k = max(k, a[i] - a[i - 1]);
        }
    }
    cout << k << '\n';
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