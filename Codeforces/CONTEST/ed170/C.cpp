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
    ll n, k, a, sum;
    cin >> n >> k;
    ll ans = 0;
    ll idx = 0;
    map<ll, ll> mp;
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.insert(a);
        mp[a]++;
        
    }
    int set_seize = s.size();
    vector<ll> z(set_seize);
    vector<ll> ss(set_seize);
    
    for (auto i : s)
    {
        z[idx] = mp[i];
        ss[idx] = i;
        idx++;
    }
    ll i = 0, j = i + 1;
    ll q = 1;

    ll cur = z[i];
    ans = max(ans, cur);
    while (j < s.size())
    {
        if ( ss[j - 1]!=ss[j] -1 )
        {
            i = j;
            cur = z[i];
            ans = max(ans, cur);
            q = 1;
            j = i + 1;
        }
        else if (q < k)
        {
            cur += z[j];
            ans = max(ans, cur);
            q++;
            j++;
        }
        else
        {
            ans = max(ans, cur);
            cur -= z[i];
            q--;
            i++;
        }
    }
    // coo
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