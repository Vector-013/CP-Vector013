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
    ll n, q, a, b, ans, p, x, y, d, c, j = -1, k = -1;
    cin >> n;
    bool flag = true;
    vector<ll> v(n);
    map<ll, ll> map;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        map[v[i]]++;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        d = (a * a) - (4ll * b);
        c = llround(sqrt(d));
        if ((c * c != d) || ((c + a) % 2))
            cout << 0 << " ";
        else
        {
            x = (c + a) / 2;
            y = (a - c) / 2;
            if (map[x] > 0 && map[y] > 0)
            {
                if (x != y)
                    cout << map[x] * map[y] << " ";
                else
                    cout << map[x] * (map[x] - 1) / 2 << " ";
            }
            else
                cout << 0 << " ";
        }
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