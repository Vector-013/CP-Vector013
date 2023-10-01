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
void solve()
{
    ll n, cnt = 0, b, a, dif;
    ll sum = 0;
    cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
        sum += p[i];
    }

    if ((2 * sum) % n != 0)
    {
        cout << 0 << '\n';
        return;
    }
    sort(p.begin(), p.end());
    vector<pair<ll, ll>> v;
    v.pb({p[0], 1ll});
    for (ll i = 1; i < n; i++)
    {
        if (p[i] != p[i - 1])
            v.pb({p[i], 1ll});
        else
            v[v.size() - 1].second++;
    }
    vector<int> w(v.size());
    for (ll i = 0; i < v.size(); i++)
        w[i] = v[i].first;

    for (ll i = 0; i < w.size(); i++)
    {
        a = w[i];
        b = ((2ll * sum) / n) - a;
        dif = lower_bound(w.begin() + i, w.end(), b) - w.begin();
        if (i < w.size() - 1 && dif < n && b == *lower_bound(w.begin() + i, w.end(), b))
        {

            if (v[i].first != v[dif].first)
                cnt += v[i].second * v[dif].second;
            else
                cnt += ((v[i].second) * (v[i].second - 1ll)) / 2ll;
        }
        if (i == w.size() - 1 && a == b)
            cnt += ((v[i].second) * (v[i].second - 1ll)) / 2ll;
    }
    cout << cnt << '\n';
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