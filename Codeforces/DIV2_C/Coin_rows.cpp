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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> w(n);
    int sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum1 += v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int mini = inf, maxi = 0;
    int s1 = sum1, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s1 -= v[i];
        if (i > 0)
            s2 += w[i - 1];
        mini = min(mini, max(s1, s2));
    }
    cout << mini << '\n';
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