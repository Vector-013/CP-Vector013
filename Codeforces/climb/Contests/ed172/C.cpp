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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> suf(n, 0);
    suf[n - 1] = (s[n - 1] == '1') ? 1 : -1;
    for (int i = n - 2; i >= 0; i--)
        suf[i] = (s[i] == '1') ? suf[i + 1] + 1 : suf[i + 1] - 1;
    ll sum = 0;
    suf.erase(suf.begin());
    sort(suf.begin(), suf.end(), greater());

    for (int i = 1; i < n; i++)
    {
        sum += suf[i - 1];
        if (sum >= k)
        {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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