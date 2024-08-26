#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> v(w);
    ll ans = 0;
    vector<vector<int>> z(n, vector<int>(m, 0));
    for (int i = 0; i < w; i++)
        cin >> v[i];

    int left, right, top, bottom;
    vector<ll> x(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            left = -max(0, i - k + 1) + min(i + k - 1, n - 1) - k + 1 + 1;
            top = -max(0, j - k + 1) + min(j + k - 1, m - 1) - k + 2;

            z[i][j] = left * top;
            // cout << z[i][j] << ' ';
            x[i * m + j] = z[i][j];
        }
        // cout << '\n';
    }
    sort(v.begin(), v.end(), greater<ll>());
    sort(x.begin(), x.end(), greater<ll>());
    // for (int i = 0; i < n * m; i++)
    //     cout << x[i];
    // cout << '\n';
    for (int i = 0; i < w; i++)
    {
        ans += v[i] * x[i];
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