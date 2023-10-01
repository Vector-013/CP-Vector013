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
    int n, m;
    cin >> n >> m;
    if (m == 1)
    {
        cout << "YES" << '\n';
        return;
    }
    if (n == 1)
    {
        cout << "YES" << '\n';
        return;
    }
    if (n % 2 == 0)
    {
        cout << "NO" << '\n';
        return;
    }
    if (m >= n)
    {
        cout << "NO" << '\n';
        return;
    }
    if (n % 2 == 1)
    {
        int f;
        if (isprime(n))
        {
            cout << "YES" << '\n';
            return;
        }

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (m >= i || m >= n / i)
                {
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
        cout << "YES" << '\n';
    }
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