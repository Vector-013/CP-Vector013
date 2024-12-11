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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> scr(n);
    for (int i = 0; i < n; i++)
    {
        scr[i] = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                scr[i]++;
            }
        }
    }
    sort(scr.begin(), scr.end());
    cout << scr[0] << '\n';
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