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
void solve()
{
    ll n, x, a, sum = 0, cnt = 0;
    cin >> n;
    map<ll, ll> freq;
    freq[0]++;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum += a;
        if (sum >= 0)
        {
            cnt += freq[sum % n];
            freq[sum % n]++;
        }
        else
        {
            cnt += freq[(n + (sum % n)) % n];
            freq[(n + (sum % n)) % n]++;
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
