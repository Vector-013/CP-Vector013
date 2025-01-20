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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    if ((n + m) % 2 == 0)
    {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> maxi(n, vector<int>(m, -inf));
    maxi[0][0] = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
                maxi[i][j] = maxi[i][j - 1] + a[i][j];
            else if (j == 0)
                maxi[i][j] = maxi[i - 1][j] + a[i][j];
            else
                maxi[i][j] = max(maxi[i - 1][j], maxi[i][j - 1]) + a[i][j];
        }
    }
    vector<vector<int>> mini(n, vector<int>(m, inf));
    mini[0][0] = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
                mini[i][j] = mini[i][j - 1] + a[i][j];
            else if (j == 0)
                mini[i][j] = mini[i - 1][j] + a[i][j];
            else
                mini[i][j] = min(mini[i - 1][j], mini[i][j - 1]) + a[i][j];
        }
    }
    if (maxi[n - 1][m - 1] >= 0 && mini[n - 1][m - 1] <= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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