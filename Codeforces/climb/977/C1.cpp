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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    unordered_set<int> s;
    vector<int> comp;
    for (int i = 0; i < m; i++)
    {
        if (s.find(b[i]) == s.end())
        {
            s.insert(b[i]);
            comp.push_back(b[i]);
        }
    }
    int z = comp.size();
    for (int i = 0; i < z; i++)
    {
        if (a[i] == comp[i])
        {
            continue;
        }
        else
        {
            cout << "TIDAK" << '\n';
            return;
        }
    }
    cout << "YA" << '\n';
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