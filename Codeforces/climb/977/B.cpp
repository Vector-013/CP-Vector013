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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cnt[v[i]]++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++)
    {
        if (!cnt[i])
        {
            if (cnt[i - k] > 1)
            {
                cnt[i] += cnt[i - k] - 1;
            }
            else
            {
                cout << i << '\n';
                return;
            }
        }
        else
        {
            if (cnt[i - k] > 1)
            {
                cnt[i] += cnt[i - k] - 1;
            }
        }
    }
    cout << n + 1 << '\n';
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