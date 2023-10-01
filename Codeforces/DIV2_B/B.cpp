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
    int n, m, mini, a, seci = inf;
    ll sum = 0;
    cin >> n;
    vector<int> mon(n);
    vector<int> sec;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        mini = inf;
        v[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> a;
            v[i][j] = a;
            if (a < mini)
                mini = v[i][j];
        }
        mon[i] = mini;
    }
    for (int i = 0; i < n; i++)
    {
        seci = inf;
        if (v[i].size() > 1)
        {
            ll cnt = 0;
            for (int j = 0; j < v[i].size(); j++)
            {

                if ((v[i][j] < seci))
                {
                    if (v[i][j] == mon[i] && cnt == 0)
                    {
                        cnt++;
                        continue;
                    }
                    seci = v[i][j];
                }
            }
            sec.pb(seci);
        }
    }
    if (sec.size() > 0)
        sort(sec.begin(), sec.end());
    sort(mon.begin(), mon.end());
    if (n == 1)
    {
        cout << mon[0] << '\n';
        return;
    }
    for (int i = 1; i < sec.size(); i++)
    {
        sum += sec[i];
    }

    sum += mon[0];
    cout << sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}