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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (v.size() == 1)
    {
        cout << 1 << '\n'
             << v[0] << '\n';
        return;
    }
    sort(v.begin(), v.end());
    ll difsum = 0;
    for (int i = 1; i < n; i++)
    {
        if ((v[i] - v[i - 1]) & 1ll)
        {
            cout << -1 << '\n';
            return;
        }
        difsum += v[i] - v[i - 1];
    }
    int yea = 40;
    bool flag = 0;
    vector<ll> z;
    ll difum;
    while (yea--)
    {
        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
                flag = true;
        }
        if (flag)
        {
            sort(v.begin(), v.end());
            difsum = 0;
            for (ll i = 1; i < n; i++)
                difsum += v[i] - v[i - 1];
            difsum /= 2ll;
            z.push_back(difsum);
            for (ll i = 0; i < n; i++)
                v[i] = (ll)abs(v[i] - difsum);
            // for (int i = 0; i < n; i++)
            // {
            //     cout << v[i] << " ";
            // }
        }
        else
        {
            z.push_back(v[0]);
            break;
        }
        flag = 0;
    }
    cout << z.size() << '\n';
    for (ll i = 0; i < z.size(); i++)
        cout << z[i] << " ";
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}