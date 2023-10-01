#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <numeric>
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
    int n, k, cnt = 1;
    cin >> n >> k;
    vector<string> v(n);
    string s;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    s = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] == s)
            cnt++;
    }
    cout << cnt << '\n';
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