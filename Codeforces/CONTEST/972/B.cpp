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
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    int d;
    int ans;
    for (int i = 0; i < q; i++)
    {
        cin >> d;
        auto ht = upper_bound(b.begin(), b.end(), d) - b.begin();
        auto lt = lower_bound(b.begin(), b.end(), d) - b.begin() - 1;
        //cout << "ht = " << ht << " " << lt << '\n';
        if (ht == m)
        {
            ans = n - b[ht - 1];
        }
        else if (lt == -1)
        {
            ans = b[0] - 1;
        }
        else
        {
            ans = (b[ht] - b[lt]) / 2;
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