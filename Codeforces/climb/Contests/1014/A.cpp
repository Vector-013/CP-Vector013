#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n, ans = 0, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        ans += v[i];
        cnt += (v[i] & 1);
    }
    if (cnt == n || not cnt)
        cout << *max_element(v.begin(), v.end()) << '\n';
    else
        cout << ans - cnt + 1 << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}