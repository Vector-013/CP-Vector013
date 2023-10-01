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
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
bool pair_first_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
ll maxsub(vector<int> v)
{
    int s = 0, start = 0;
    int e = 0, end = 0;
    ll currsum = 0;
    ll maxsum = -linf;
    for (int i = 0; i < v.size(); i++)
    {
        currsum += v[i];
        if (maxsum < currsum)
        {
            end = i;
            start = s;
            maxsum = currsum;
        }
        if (currsum < 0)
        {
            currsum = 0;
            s = i + 1;
        }
    }
    return maxsum;
}
int gcd(int a, int b)
{
    int result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
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
/*---------------------------------------------------------------------------------------------------------------------------*/
vector<ll> v;
void solve()
{
    v.clear();
    ll n, temp, cur, ans = inf, curans, j, a, tempans;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.insert(a);
    }
    for (auto i : s)
        v.pb(i);
    n = v.size();
    if (n <= 3)
    {
        cout << 0 << '\n';
        return;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        cur = (v[i] - v[0] + 1) / 2;
        j = lower_bound(v.begin() + i + 1, v.end(), ((v[i + 1] + v[n - 1]) / 2)) - v.begin();

        curans = max(cur, max(((v[n - 1] - v[j] + 1) / 2), ((v[j - 1] - v[i + 1] + 1) / 2)));
        if (((v[i + 1] + v[n - 1]) / 2) == v[j] && j < n)
        {
            tempans = max(cur, max(((v[n - 1] - v[j + 1] + 1) / 2), ((v[j] - v[i + 1] + 1) / 2)));
            curans = min(curans, tempans);
        }
        ans = min(ans, curans);
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