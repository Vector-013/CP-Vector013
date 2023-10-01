#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
bool pair_first_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}
bool isprime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = sqrt(n); i >= 2; i--)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int dist(int x, int y, int m, int n)
{
    return abs(m - x) + abs(n - y);
}
void solve()
{
    int m, n, a, b, len;
    cin >> m >> n;
    vector<int> v;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            len = max(max(dist(i, j, m, n), dist(i, j, 1, 1)), max(dist(i, j, m, 1), dist(i, j, 1, n)));
            v.pb(len);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m * n; i++)
        cout << v[i] << " \n"[i == m * n - 1];
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