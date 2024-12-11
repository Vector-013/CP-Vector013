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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] += i;
    }
    map<ll, vector<ll>> g;
    for (ll i = 0; i < n; i++)
    {
        g[v[i]].push_back(v[i] + i);
    }
    set<ll> pos;
    auto possi = [&](auto self, ll a) -> void
    {
        if (pos.find(a) != pos.end())
            return;
        pos.insert(a);
        for (ll u : g[a])
        {
            self(self, u);
        }
    };
    possi(possi, n);
    cout << *prev(pos.end()) << '\n';
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