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
    vector<int> a(n);
    map<int, int> mp;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        s.insert(a[i]);
    }
    sort(a.begin(), a.end());
    int z = s.size();
    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] == 1)
            cnt++;
    }
    ans += 2 * (cnt / 2 + (cnt % 2));
    // cout << ans << '\n';
    z -= cnt;
    ans += z;
    // if (cnt % 2)
    // {
    //     ans += z / 2;
    // }
    // else
    // {
    //     ans += z / 2 + (z % 2);
    // }
    cout << ans << '\n';
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