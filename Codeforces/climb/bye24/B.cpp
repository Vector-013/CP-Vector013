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
    ll n;
    cin >> n;
    vector<ll> l(n), r(n);
    vector<ll> sum(2 * n + 5, 0);
    vector<ll> mrk(2 * n + 5, 0);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        if (l[i] == r[i])
        {
            mrk[l[i]] = 1;
            freq[l[i]]++;
        }
    }
    for (int i = 1; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + mrk[i];
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (l[i] >= r[i])
        {
            ans = freq[l[i]] == 1 ? ans + '1' : ans + '0';
        }
        else
        {
            ans = (sum[r[i]] - sum[l[i] - 1] < r[i] - l[i] + 1) ? ans + '1' : ans + '0';
        }
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