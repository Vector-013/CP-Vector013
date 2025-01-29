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
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int maxxb = 0, minxb = inf, maxyb = 0, minyb = inf;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
            {
                maxxb = max(maxxb, i);
                minxb = min(minxb, i);
                maxyb = max(maxyb, j);
                minyb = min(minyb, j);
            }
        }
    }
    for (int x = minxb; x <= maxxb; x++)
    {
        for (int y = minyb; y <= maxyb; y++)
        {
            if (s[x][y] == '.')
            {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}