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
void solve()
{
    ll n, a, b, cnt = 0, ans = 0, j;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> sum(n);
    vector<ll> dif(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        x[i] = a;
        y[i] = b;
        sum[i] = a + b;
        dif[i] = a - b;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(sum.begin(), sum.end());
    sort(dif.begin(), dif.end());
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        j = i;
        while (j < n && x[i] == x[j])
        {
            cnt++;
            j++;
        }
        ans += (cnt * (cnt - 1) / 2) * 2;
        i = j - 1;
    }
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        j = i;
        while (j < n && y[i] == y[j])
        {
            cnt++;
            j++;
        }
        ans += (cnt * (cnt - 1) / 2) * 2;
        i = j - 1;
    }
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        j = i;
        while (j < n && sum[i] == sum[j])
        {
            cnt++;
            j++;
        }
        ans += (cnt * (cnt - 1) / 2) * 2;
        i = j - 1;
    }
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        j = i;
        while (j < n && dif[i] == dif[j])
        {
            cnt++;
            j++;
        }
        ans += (cnt * (cnt - 1) / 2) * 2;
        i = j - 1;
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