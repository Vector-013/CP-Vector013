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
    int n, cnt;
    string s;
    cin >> n;
    vector<int> v(n + 1), vis(n + 1, 0);
    map<int, int> cmp;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cin >> s;
    s = '0' + s;
    int cyc = 0;
    int j;
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        if (vis[i] == 0)
        {
            j = i;
            cyc++;
            while (vis[j] == 0)
            {
                cmp[j] = cyc;
                if (s[j] == '0')
                {
                    cnt++;
                }
                vis[j] = 1;
                j = v[j];
            }
            mp[cyc] = cnt;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << mp[cmp[i]] << " ";
    }
    cout << '\n';
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