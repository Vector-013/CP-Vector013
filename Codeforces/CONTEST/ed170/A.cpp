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
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    int x = 0;
    int p = min(n, m);
    for (int i = 0; i < p; i++)
    {
        if (s[i] == t[i])
        {
            x++;
        }
        else
        {
            break;
        }
    }
    if (x > 0)
        cout << x + 1 + n - x + m - x << '\n';
    else
        cout << n + m << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}