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
    string s;
    cin >> n >> s;
    int a = 0, b = 0, c = 0, d = 0, q = 0;
    for (int i = 0; i < 4 * n; i++)
    {
        if (s[i] == 'A')
            a++;
        if (s[i] == 'B')
            b++;
        if (s[i] == 'C')
            c++;
        if (s[i] == 'D')
            d++;
        if (s[i] == '?')
            q++;
    }
    int ans = 0;
    if (a <= n)
        ans += a;
    else
        ans += n;
    if (b <= n)
        ans += b;
    else
        ans += n;
    if (c <= n)
        ans += c;
    else
        ans += n;
    if (d <= n)
        ans += d;
    else
        ans += n;
    cout << ans << '\n';
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