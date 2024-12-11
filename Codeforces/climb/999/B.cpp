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
    ll sum = 0, sumo = 0, sume = 0, cnte = 0, cnto = 0;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        if (i & 1)
        {
            sumo += v[i];
            cnto++;
        }
        else
        {
            sume += v[i];
            cnte++;
        }
    }
    if (sum % n != 0)
    {
        cout << "NO\n";
        return;
    }
    ll avg = sum / n;
    if (sumo != cnto * avg || sume != cnte * avg)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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