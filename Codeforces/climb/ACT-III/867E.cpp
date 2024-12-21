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
    int n;
    string s;
    cin >> n >> s;
    if (n & 1)
    {
        cout << "-1\n";
        return;
    }
    ll ans = 0;
    map<char, int> cnt;
    map<char, int> fre;
    for (auto c : s)
    {
        fre[c]++;
        if (fre[c] > n / 2)
        {
            cout << "-1\n";
            return;
        }
    }
    ll tot = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
        {
            cnt[s[i]]++;
            tot++;
        }
    }
    for (auto [c, f] : cnt)
    {
        ans = max(ans, 1ll * f);
    }
    ans = max(ans, (tot + 1ll) / 2ll);
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