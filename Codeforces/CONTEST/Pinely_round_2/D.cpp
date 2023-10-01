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
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (v[i][j] == 'U' || v[i][j] == 'D')
                cnt++;
        if (cnt & 1)
        {
            cout << -1 << '\n';
            return;
        }
        cnt = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == 'L' || v[j][i] == 'R')
                cnt++;
        }
        if (cnt & 1)
        {
            cout << -1 << '\n';
            return;
        }
        cnt = 0;
    }
    string s = string(m, 'q');
    char c;
    vector<string> w(n);
    for (int i = 0; i < n; i++)
        w[i] = s;
    for (int i = 0; i < n; i++)
    {
        c = 'W';
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.')
                w[i][j] = '.';
            else if (v[i][j] == 'U')
            {
                w[i][j] = c;
                c = ((c == 'W') ? 'B' : 'W');
                w[i + 1][j] = c;
            }
        }
    }
    for (int i = 0; i < m - 1; i++)
    {
        c = 'W';
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == 'L')
            {
                w[j][i] = c;
                c = ((c == 'W') ? 'B' : 'W');
                w[j][i + 1] = c;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << w[i];
        cout << '\n';
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