#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
auto YES = []
{ cout << "YES\n"; };
auto NO = []
{ cout << "NO\n"; };

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int si = -1, pi = n, cs = 0, cp = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 's')
        {
            si = max(si, i);
            cs++;
        }
        if (s[i] == 'p')
        {
            pi = min(pi, i);
            cp++;
        }
    }
    bool yea = false;
    if (pi == n || si == -1)
        yea = true;
    if (si > pi || (cs > 1 && cp > 1))
        yea = false;
    if (cs == 1 && si == 0)
        yea = true;
    if (cp == 1 && pi == n - 1)
        yea = true;
    yea ? YES() : NO();
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