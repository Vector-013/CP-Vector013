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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (!(k & 1))
    {
        sort(s.begin(), s.end());
        cout << s << '\n';
        return;
    }
    else
    {
        string q, w;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                q.pb(s[i]);
            else
                w.pb(s[i]);
        }
        sort(q.begin(), q.end());
        sort(w.begin(), w.end());
        string ans = string(n, 'q');
        int j = 0, k = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                ans[i] = q[j];
                j++;
            }
            else
            {
                ans[i] = w[k];
                k++;
            }
        }
        cout << ans << '\n';
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