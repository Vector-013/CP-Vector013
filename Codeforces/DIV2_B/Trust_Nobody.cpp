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
    int n, ans = 0, tru = 0, lie = 0, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        tru += v[i];
    }
    if (tru == 0)
    {
        cout << 0 << '\n';
        return;
    }

    sort(v.begin(), v.end());
    int i = n - 1;
    while (i > 0)
    {
        while (v[i] == v[i - 1])
        {
            cnt++;
            i--;
        }
        if (v[i] <= cnt + 1)
        {
            cout << -1 << '\n';
            return;
        }
        if (v[i - 1] <= cnt + 1)
        {
            cout << cnt + 1 << '\n';
            return;
        }
        i--;
        cnt++;
    }
    cout << -1 << '\n';
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