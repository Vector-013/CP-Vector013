#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j] == '1')
            {
                bool c = 1;
                for (int x = 0; x < i; ++x)
                {
                    if (v[x][j] == '0')
                    {
                        c = 0;
                        break;
                    }
                    c = 1;
                }
                if (not c)
                {
                    c = 1;
                    for (int z = 0; z < j; ++z)
                    {
                        if (v[i][z] == '0')
                        {
                            c = 0;
                            break;
                        }
                        c = 1;
                    }
                }
                if (not c)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}