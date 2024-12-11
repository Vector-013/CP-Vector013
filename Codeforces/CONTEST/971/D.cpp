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
    ll n, ans = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    map<int, int> m0, m1;
    auto comp = [&](auto p1, auto p2)
    {
        if (p1.first > p2.first)
            return true;
        else if (p2.first > p1.first)
            return false;
        return p1.second >= p2.second;
    };
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].second)
            m1[v[i].first]++;
        else
            m0[v[i].first]++;
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 1; i < n; i++)
    {
        if (v[i].first == v[i - 1].first)
            ans += n - 2;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i].second)
        {
            if (m0[v[i].first - 1] && m0[v[i].first + 1])
                ans++;
        }
        else
        {
            if (m1[v[i].first - 1] && m1[v[i].first + 1])
                ans++;
        }
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