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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k);
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        v[i % k].push_back(a);
    }
    vector<int> flag(k, 0);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < v[i % k].size(); j++)
        {
            if (v[i % k][j] % k == i % k)
                continue;

            else
            {

                flag[i % k]++;
                if (flag[i % k] > 1)
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    int cnt = 0;
    for (int m = 0; m < k; m++)
    {
        cnt += flag[m % k];
    }
    if (cnt == 0)
    {
        cout << 0 << '\n';
        return;
    }
    else if (cnt == 2)
    {
        cout << 1 << '\n';
        return;
    }
    else
    {
        cout << -1 << '\n';
        return;
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