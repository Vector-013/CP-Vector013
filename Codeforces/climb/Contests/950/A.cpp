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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;
    ll ans = 0;
    for (char c = 'A'; c <= 'G'; c++)
    {
        ans += (m - mp[c]) * (m > mp[c]);
    }
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