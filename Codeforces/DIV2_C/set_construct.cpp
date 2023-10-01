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
    int n;
    string s;
    cin >> n;
    vector<vector<bool>> q;
    vector<bool> w(n + 1, false);
    q.assign(n + 1, w);
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == '1')
                q[i][j + 1] = 1;
    }
    vector<set<int>> v(n + 1);
    for (int i = 1; i <= n; i++)
        v[i].insert(i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (q[i][j])
                v[j].insert(v[i].begin(), v[i].end());
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i].size() << " ";
        for (auto it = v[i].begin(); it != v[i].end(); it++)
            cout << *it << " ";
        cout << '\n';
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