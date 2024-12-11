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
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    int s = 0;
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r -= a[i] / 2;
        if (a[i] % 2)
            left++;
        s += a[i];
    }
    if (r >= left)
    {
        cout << s << "\n";
        return;
    }
    else
    {
        int unhappy = 0;
        unhappy = 2 * (left - r);
        cout << s - unhappy << "\n";
        return;
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