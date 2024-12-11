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
    int k = n % 5, m = n / 5;
    string s = string(((n / 5) + (k-- > 0 ? 1 : 0)), 'a') + string(((n / 5) + (k-- > 0 ? 1 : 0)), 'e') + string(((n / 5) + (k-- > 0 ? 1 : 0)), 'i') + string(((n / 5) + (k-- > 0 ? 1 : 0)), 'o') + string(((n / 5) + (k-- > 0 ? 1 : 0)), 'u');
    cout << s << '\n';
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