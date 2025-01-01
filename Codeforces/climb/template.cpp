#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
auto mex = [](set<int> &s) -> int
{
    int mex = 0;
    while (s.count(mex))
        mex++;
    return mex;
};
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    if (a == 0)
        return b;

    if (a > b)
        return gcd(b, a % b);

    return gcd(a, b % a);
}

ll maxi(ll a, ll b)
{
    if (a > b)
        return a;

    else
        return b;
}

ll mini(ll a, ll b)
{
    if (a > b)
        return b;

    else
        return a;
}

int modpower(ll a, ll b, ll c)
{
    ll r = 1;

    a = a % c;

    while (b > 0)
    {
        if (b % 2 == 1)
            r = (r * a) % c;

        b = b / 2;
        a = (a * a) % c;
    }

    return r;
}
void solve()
{
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