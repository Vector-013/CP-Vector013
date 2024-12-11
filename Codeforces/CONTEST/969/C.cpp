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
    int n, a, b;
    cin >> n >> a >> b;
    int g = gcd(a, b);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] %= g;
    }
    sort(v.begin(), v.end());

    int ans = v[n - 1] - v[0];
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, g - (v[i + 1] - v[i]));
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