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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    ll sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] < k)
        {
            sum += a[i];
            continue;
        }
        if (sum + a[i] == k)
        {
            cout << 0 << '\n';
            return;
        }
        else
        {
            cout << k - sum << '\n';
            return;
        }
    }
    cout << k - sum << '\n';
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