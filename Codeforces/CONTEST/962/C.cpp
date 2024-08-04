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
    int n, m;
    cin >> n >> m;
    string s, x;
    cin >> s >> x;
    vector<vector<int>> v(n, vector<int>(26));
    vector<vector<int>> a(n, vector<int>(26));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            v[i][j] = 0;
            a[i][j] = 0;
        }
    }
    v[0][s[0] - 97] = 1;
    a[0][x[0] - 97] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (j == s[i] - 97)
            {
                v[i][j] = v[i - 1][j] + 1;
                continue;
            }
            v[i][j] = v[i - 1][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (j == x[i] - 97)
            {
                a[i][j] = a[i - 1][j] + 1;
                continue;
            }
            a[i][j] = a[i - 1][j];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //         cout << v[i][j] << " ";
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //         cout << a[i][j] << " ";
    //     cout << '\n';
    // }
    int l, r, sum;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        l--;
        r--;
        sum = 0;
        if (l)
        {
            for (int j = 0; j < 26; j++)
            {
                if (v[l - 1][j] - v[r][j] == a[l - 1][j] - a[r][j])
                    continue;
                sum += abs((v[l - 1][j] - v[r][j]) - (a[l - 1][j] - a[r][j]));
            }
            cout << sum / 2 << '\n';
            continue;
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (v[r][j] == a[r][j])
                    continue;
                sum += abs((v[r][j]) - (a[r][j]));
            }
            cout << sum / 2 << '\n';
            continue;
        }
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