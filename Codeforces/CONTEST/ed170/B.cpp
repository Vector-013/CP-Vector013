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
const ll MOD = 1e9 + 7;

long long bin_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}
void solve()
{
    int t;
    cin >> t;
    vector<ll> v(t), w(t);
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < t; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout << bin_exp(2, w[i], MOD) << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}