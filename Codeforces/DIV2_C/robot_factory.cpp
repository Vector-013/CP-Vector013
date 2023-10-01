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
vector<vector<bool>> vis;
vector<vector<ll>> v;
vector<int> ans;
ll dfs(int x, int y)
{
    // cout << "called " << '\n';
    ll cnt = 1;
    if (vis[x][y])
    {
        return 0;
    }
    vis[x][y] = true;
    if (v[x][y] % 8 < 4)
    {
        cnt += dfs(x, y + 1);
    }
    if (v[x][y] % 4 < 2)
    {
        cnt += dfs(x + 1, y);
    }
    if (v[x][y] % 2 == 0)
    {
        cnt += dfs(x, y - 1);
    }
    if (v[x][y] < 8)
    {
        cnt += dfs(x - 1, y);
    }
    return cnt;
}
void solve()
{
    ll n, m, a = 0;
    cin >> n >> m;
    v.assign(n, vector<ll>(m));
    vis.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                ans.pb(dfs(i, j));
            }
        }
        sort(ans.begin(), ans.end(), greater<int>());
        for (auto z : ans)
            cout << z << " ";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}