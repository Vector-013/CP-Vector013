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
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> ss;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        ss.insert(v[i]);
    }
    int p;
    cin >> p;
    while (p--)
    {
        vector<ll> x(26, -linf);
        map<int, char> m;
        bool f = 1;
        string s;
        cin >> s;
        if (s.length() != n)
        {
            cout << "NO\n";
            continue;
        }
        if (ss.size() > 26)
        {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (m[v[i]] == 0 && x[s[i] - 97] == -linf)
            {
                m[v[i]] = s[i];
                x[s[i] - 97] = v[i];
                // cout << s[i] << " " << v[i] << '\n';
            }
            else
            {
                if ((m[v[i]] != s[i]) || (x[s[i] - 97] != v[i]))
                {
                    cout << "NO\n";
                    f = 0;
                    break;
                }
            }
        }
        if (f == 1)
            cout << "YES\n";
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