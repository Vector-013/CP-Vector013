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
int cnt, curr;
vector<vector<pair<int, int>>> v;
vector<int> ans;
void dfs(int x, int p)
{
    if (v[x].size() == 1)
    {
        cnt++;
    }
    if (cnt == 2)
        return;
    for (auto u : v[x])
    {
        if (u.first != p)
        {
            curr = ((curr == 2) ? 3 : 2);
            ans[u.second] = curr;
            dfs(u.first, x);
        }
    }
}
void solve()
{
    int n, a, b, stp;
    curr = 2, cnt = 0;
    cin >> n;
    v.clear();
    ans.clear();
    v.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        v[a].pb({b, i});
        v[b].pb({a, i});
    }
    ans.resize(n);
    for (int i = 1; i <= n; i++)
    {
        if (!(v[i].size() == 1 || v[i].size() == 2))
        {
            cout << -1 << '\n';
            return;
        }
        if (v[i].size() == 1)
            stp = i;
    }
    dfs(stp, -1);
    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
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