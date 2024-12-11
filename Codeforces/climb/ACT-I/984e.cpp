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
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> v(k, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> v[j][i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            v[i][j] |= v[i][j - 1];
        }
    }
    // cout << "\n\n";
    // for (int i = 0; i < k; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "\n\n";

    for (int i = 0; i < q; i++)
    {
        int y;
        cin >> y;
        bool sane = true;
        int mini = 0, maxi = n;
        for (int j = 0; j < y; j++)
        {
            int a, b, r, t;
            char x;
            cin >> a >> x >> b;
            a--;
            if (x == '<')
            {
                r = lower_bound(v[a].begin(), v[a].end(), b) - v[a].begin();
                maxi = min(maxi, r);
                // cout << maxi << '\n';
                if (r == 0)
                    sane = false;
            }
            else
            {
                r = upper_bound(v[a].begin(), v[a].end(), b) - v[a].begin();
                mini = max(mini, r);
                // cout << mini << '\n';
                if (r == n)
                    sane = false;
            }
        }
        if (!sane)
        {
            cout << -1 << '\n';
            continue;
        }
        // cout << mini << ' ' << maxi << '\n';
        if (mini <= maxi - 1)
        {
            cout << mini + 1 << '\n';
            continue;
        }
        cout << -1 << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}