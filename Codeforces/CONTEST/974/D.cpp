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
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> v(n + 2, 0);
    int l, r;
    for (int i = 0; i < k; i++)
    {
        cin >> l >> r;
        v[max(l - d + 1, 1)]++;
        v[r + 1]--;
    }
    for (int i = 2; i <= n; i++)
    {
        v[i] += v[i-1];
    }

    int a = -inf, b = -inf, m = inf, i = d;
    a = max_element(v.begin() + 1, v.begin() + n - d + 2) - v.begin();
    b = min_element(v.begin() + 1, v.begin() + n - d + 2) - v.begin();
    cout << a << " " << b << '\n';
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
