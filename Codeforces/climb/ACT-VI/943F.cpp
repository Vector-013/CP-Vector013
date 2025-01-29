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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 0);
    vector<int> prexor(n + 1, 0);
    map<int, set<int>> mp;
    mp[0].insert(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prexor[i] = prexor[i - 1] ^ a[i];
        mp[prexor[i]].insert(i);
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        int z = prexor[l - 1] ^ prexor[r];
        if (z == 0)
        {
            cout << "YES\n";
            continue;
        }
        int id1 = *mp[prexor[r]].lower_bound(l);
        int id2 = *(--(mp[prexor[l - 1]].lower_bound(r)));
        cout << (id2 > id1 ? "YES" : "NO") << '\n';
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