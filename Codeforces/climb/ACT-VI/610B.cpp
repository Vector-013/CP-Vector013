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
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll prf = 0;
    ll ans = 0;

    for (int i = 0; i < k; i++)
    {
        ll sum = prf;
        if (sum > p)
            break;
        ll cnt = i;
        for (int j = i + k - 1; j < n; j += k)
        {
            if (sum + a[j] <= p)
            {
                cnt += k;
                sum += a[j];
            }
            else
            {
                break;
            }
        }
        prf += a[i];
        ans = max(ans, cnt);
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