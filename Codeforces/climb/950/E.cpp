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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    vector<int> row(n * m), col(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
            row[a[i][j]] = i;
            col[a[i][j]] = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
            b[i][j]--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int curr = row[b[i][0]];
        swap(a[curr], a[i]);
        for (int j = 0; j < m; j++)
        {
            row[a[curr][j]] = curr;
            row[a[i][j]] = i;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int curr = col[b[0][i]];
        for (int j = 0; j < n; j++)
        {
            swap(a[j][curr], a[j][i]);
            col[a[j][curr]] = curr;
            col[a[j][i]] = i;
        }
    }
    cout << ((a == b) ? "YES\n" : "NO\n");
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