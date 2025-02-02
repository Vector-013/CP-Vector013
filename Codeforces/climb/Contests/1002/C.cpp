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
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<ll> sfx1(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[i][j] == 1)
            {
                sfx1[i]++;
            }
            else
            {
                break;
            }
        }
    }
    sort(sfx1.begin(), sfx1.end());
    ll mex = 1;
    for (int i = 0; i < n; i++)
    {
        if (sfx1[i] >= mex)
            mex++;
    }
    cout << min(n, mex) << '\n';
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
