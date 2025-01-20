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
    vector<int> ans(n);
    for (ll i = 0; i < n - 1; i++)
        ans[i] = i + 1;
    ans[n - 1] = 1;
    ans[2] = 1;
    for (auto &x : ans)
        cout << x << ' ';
    cout << '\n';
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