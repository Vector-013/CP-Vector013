#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
#define pb push_back
#define pp pop_back
#define f(i, n) for (int i = 0; i < n; i++)
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
ll maxsubsum(vector<ll> v)
{
    ll s = 0, start = 0, end = 0, currsum = 0, maxsum = -linf;
    for (int i = 0; i < v.size(); i++)
    {
        currsum += v[i];
        if (currsum > maxsum)
        {
            start = s;
            end = i;
            maxsum = currsum;
        }
        if (currsum < 0) // maxlen (<= for minlen)
        {
            currsum = 0;
            s = i + 1;
        }
    }
    return maxsum;
}
int BinarySearch(vector<int> v, int key, int idx)
{
    int s = 0;
    int e = v.size();
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] > key)
            e = mid - 1;
        else if (v[mid] < key)
            s = mid + 1;
        else
        {
            if (mid == idx)
                return min(v[mid + 1], v[mid - 1]);
        }
    }
    return -1;
}
int gcd(int x, int y)
{
    int a = max(x, y);
    int b = min(x, y);
    int rem = a % b;
    while (rem != 0)
    {
        a = b;
        b = rem;
        rem = a % b;
    }
    return b;
}
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n--)
        ans *= a;
    return ans;
}
bool isprime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool pairsort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
void solve()
{
    int n, ans = 0, len;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    f(i, n) v[i] = i + 1;
    do
    {

        s.clear();
        f(i, n)
        {
            if (i == n - 1)
                s.insert(gcd(v[i], v[0]));
            else
                s.insert(gcd(v[i], v[i + 1]));
        }
        len = s.size();
        ans = max(ans, len);
        if (len == 3)
        {
            f(i, n) cout << v[i] << " ";
            cout << '\n';
        }

    } while (next_permutation(v.begin(), v.end()));
    cout << len << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}