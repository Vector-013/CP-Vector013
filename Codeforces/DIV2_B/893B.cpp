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
    ll n, m, d, cnt = 1, mini = linf, temp = 0, curr = 0;
    cin >> n >> m >> d;
    cnt = m + 1;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i];
    vector<int> dif(m + 1);
    dif[0] = v[0] - 1;
    dif[m] = n - v[m - 1];
    for (int i = 1; i < m; i++)
        dif[i] = v[i] - v[i - 1];
    for (int i = 0; i <= m; i++)
        if (dif[i] > d)
            cnt++;
    for (int i = 0; i < m; i++)
    {
        if ((dif[i] + dif[i + 1]) % d == 0)
        {
            temp = ((dif[i] + dif[i + 1]) / d) - 1 + cnt - 1;
            cout << temp << '\n';
            mini = min(temp, mini);
            if (temp == mini)
                curr++;
            else
                curr = 1;
        }
        else
        {
            temp = ((dif[i] + dif[i + 1]) / d) + cnt - 1;
            mini = min(temp, mini);
            if (temp == mini)
                curr++;
            else
                curr = 1;
        }
        cout << mini << '\n';
    }
    cout << mini << " " << curr << '\n';
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