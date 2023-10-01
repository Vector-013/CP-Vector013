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
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
bool pair_first_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
ll modder(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;

    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;

        b >>= 1;
    }

    return res;
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
    int n;
    string s, z;
    cin >> n >> s >> z;
    bool flag = true;
    string v(n, '1');
    string w(n, '0');
    if (s == z)
        flag = false;
    for (int i = 0; i < n && flag; i++)
    {
        if (s[i] + z[i] != 97)
        {
            cout << "NO" << '\n';
            return;
        }
    }
    vector<int> p, q;
    cout << "YES" << '\n';
    int k = 0;
    if (s == z)
    {
        if (s == v)
        {
            cout << 2 << '\n'
                 << 1 << " " << 1 << '\n'
                 << 2 << " " << n << '\n';
            return;
        }
        if (s == w)
        {
            cout << 0 << '\n';
            return;
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                j = i;
                while (j < n && s[j] == '0')
                    j++;
                p.pb(i);
                q.pb(j - 1);
                k++;
                i = j;
            }
        }
        if ((k & 1) == 0)
        {
            cout << k + 2 << '\n';
            for (int i = 0; i < p.size(); i++)
                cout << p[i] + 1 << " " << q[i] + 1 << '\n';
            cout << 1 << " " << 1 << '\n'
                 << 2 << " " << n << '\n';
        }
        else
        {
            cout << k + 1 << '\n';
            for (int i = 0; i < p.size(); i++)
                cout << p[i] + 1 << " " << q[i] + 1 << '\n';
            cout << 1 << " " << n << '\n';
        }
    }
    else
    {
        if (s == v)
        {
            cout << 1 << '\n'
                 << 1 << " " << n << '\n';
            return;
        }
        if (s == w)
        {
            cout << 3 << '\n'
                 << 1 << " " << n << '\n'
                 << 1 << " " << 1 << '\n'
                 << 2 << " " << n << '\n';
            return;
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                j = i;
                while (j < n && s[j] == '0')
                    j++;
                p.pb(i);
                q.pb(j - 1);
                k++;
                i = j;
            }
        }
        if (k & 1)
        {
            cout << k + 2 << '\n';
            for (int i = 0; i < p.size(); i++)
                cout << p[i] + 1 << " " << q[i] + 1 << '\n';
            cout << 1 << " " << 1 << '\n'
                 << 2 << " " << n << '\n';
        }
        else
        {
            cout << k + 1 << '\n';
            for (int i = 0; i < p.size(); i++)
                cout << p[i] + 1 << " " << q[i] + 1 << '\n';
            cout << 1 << " " << n << '\n';
        }
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