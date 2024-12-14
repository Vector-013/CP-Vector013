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
    int n, q, h, w;
    cin >> n >> q;

    vector<vector<ll>> rc(1001, vector<ll>(1001, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> h >> w;
        rc[h][w] += h * w;
    }
    vector<vector<ll>> prf(1001, vector<ll>(1001, 0));

    for (int i = 1; i < 1001; i++)
    {
        for (int j = 1; j < 1001; j++)
        {
            prf[i][j] = prf[i - 1][j] + prf[i][j - 1] - prf[i - 1][j - 1] + rc[i][j];
        }
    }

    int h1, h2, w1, w2;
    for (int i = 0; i < q; i++)
    {
        cin >> h1 >> w1 >> h2 >> w2;
        ll ans = prf[h2 - 1][w2 - 1] - prf[h1][w2 - 1] - prf[h2 - 1][w1] + prf[h1][w1];
        cout << ans << '\n';
    }
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