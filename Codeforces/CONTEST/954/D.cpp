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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2)
    {
        cout << stoi(s) << '\n';
        return;
    }
    int ans = inf;
    for (int i = 1; i < n; i++)
    {
        int ss = stoi(s.substr(i - 1, 2));
        for (int j = 0; j < n; j++)
        {
            if (j == i - 1 || j == i)
                continue;
            int x = s[j] - '0';
            ss = min(ss * x, ss + x);
        }
        ans = min(ss, ans);
    }
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