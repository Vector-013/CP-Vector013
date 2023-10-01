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
    ll n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    int los[n + 1];
    los[n] = 1e9;
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    sort(v.begin(), v.end(), pair_first_sort);
    for (int i = n - 1; i >= 0; i--)
        los[i] = min(los[i + 1], v[i].second);
    int ptr = 0;
    int hit = 0;
    while (ptr < n)
    {
        if (k <= 0)
        {
            cout << "NO" << '\n';
            return;
        }
        hit += k;
        while (ptr < n && v[ptr].first <= hit)
            ptr++;
        k -= los[ptr];
    }
    cout << "YES" << '\n';
    return;
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