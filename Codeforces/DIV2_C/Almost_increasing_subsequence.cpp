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
    int n, q, l, r, ans, sum = 0;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i >= 2 && v[i] <= v[i - 1] && v[i - 1] <= v[i - 2])
            sum++;
        w[i] = sum;
    }
    for (int z = 0; z < q; z++)
    {
        cin >> l >> r;
        if (l == r)
        {
            cout << 1 << '\n';
            continue;
        }
        if (r - l == 1)
        {
            cout << 2 << '\n';
            continue;
        }
        cout << r - l + 1 - w[r - 1] + w[l] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}