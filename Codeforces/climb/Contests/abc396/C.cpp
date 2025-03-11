#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(n), w(m);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> w[i];
    sort(b.begin(), b.end(), greater<int>());
    sort(w.begin(), w.end(), greater<int>());
    ll ans = 0;

    int cnt_posb = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
        {
            cnt_posb++;
            ans += (ll)b[i];
        }
    }
    int cnt_posw = 0;
    for (int i = 0; i < m; i++)
    {
        if (w[i] > 0)
        {
            cnt_posw++;
            if (i < cnt_posb)
                ans += (ll)w[i];
        }
    }
    if (cnt_posw > cnt_posb)
    {
        for (int i = cnt_posb; i < min(n,m); i++)
            if (b[i] + w[i] > 0)
                ans += (ll)b[i] + w[i];
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}