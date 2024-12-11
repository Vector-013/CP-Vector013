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
    vector<ll> a;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (auto & [v, u] : mp) {
        while (u >= 2) {
            a.push_back(v);
            u -= 2;
        }
    }
    if (a.size() < 4)
    {
        cout << "NO\n";
        return;
    }
    sort(a.begin(), a.end());
    ll a1 = a[0], a2 = a[1], a3 = a[a.size() - 2], a4 = a[a.size() - 1];
    if ((a4 - a1) * (a3 - a2) >= (a3 - a1) * (a4 - a2))
    {
        cout << "YES\n";
        cout << a4 << " " << a3 << " " << a4 << " " << a2 << " " << a1 << " " << a3 << " " << a1 << " " << a2 << "\n";
    }
    else
    {
        cout << "YES\n";
        cout << a3 << " " << a4 << " " << a3 << " " << a2 << " " << a1 << " " << a4 << " " << a1 << " " << a2 << "\n";
    }
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