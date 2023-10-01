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
const int INF = 2e9;
typedef long long ll;
typedef long double ld;
bool pair_first_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first >= p2.first;
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
    int n, t1, t2, tt1 = 0, tt2 = 0;
    cin >> n >> t1 >> t2;
    vector<pair<int, int>> v(n);
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end(), pair_first_sort);

    for (int i = 0; i < n; i++)
    {
        tt1 += t1;
        tt2 += t2;
        if (tt1 < tt2)
        {
            v1.pb(v[i].second);
            tt2 -= t2;
        }
        else
        {
            v2.pb(v[i].second);
            tt1 -= t1;
        }
    }
    cout << v1.size() << " ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << '\n';
    cout << v2.size() << " ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << '\n';
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