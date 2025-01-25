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
    int n,k;
    cin >> n >> k;
    vector<int> l(n), r(n), w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        w[i] = r[i] - l[i] + 1;
    }

    int minw = *min_element(w.begin(), w.end());
    int maxl = *max_element(l.begin(), l.end());
    int minr = *min_element(r.begin(), r.end());
    int ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, max(w[i] - minw, min(w[i], max(maxl - l[i], r[i] - minr))));

    cout << ans * 2 << '\n';
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