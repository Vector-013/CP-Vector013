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
bool isprime(ll n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (ll i = (ll)sqrtl(n); i >= 2; i--)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void solve()
{

    ll n, k, maxf = 0;
    cin >> n >> k;
    if (k >= n)
    {
        cout << 1 << '\n';
        return;
    }
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i <= k)
                maxf = max(maxf, n / i);
            else if (i <= k)
                maxf = max(maxf, i);
            else
                continue;
        }
    }
    cout << n / maxf << '\n';
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