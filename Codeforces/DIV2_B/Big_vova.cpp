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
    return p1.first > p2.first;
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
bool asc(int a, int b)
{
    return a >= b;
}
void solve()
{
    int n, f;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<pair<int, int>> gdc(n);
    int c = *max_element(v.begin(), v.end());
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < v.size(); i++)
        {
            gdc[i].first = gcd(c, v[i]);
            gdc[i].second = i;
        }
        sort(gdc.begin(), gdc.end(), pair_first_sort);
        c = gdc[0].first;
        cout << v[gdc[0].second] << " ";
        v.erase(v.begin() + gdc[0].second);
        gdc.resize(v.size());
    }
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