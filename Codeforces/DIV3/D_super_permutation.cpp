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
const int INF = 2e9;
typedef long long ll;
typedef long double ld;
ll power(ll n, ll i)
{
    ll ans = 1;
    while (i--)
        ans *= n;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if (n % 2 == 1)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = n; i > 0; i -= 2)
    {
        cout << i << " " << n + 1 - i << " ";
    }
    cout << '\n';
    return;
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