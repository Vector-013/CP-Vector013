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
int nc2(int n)
{
    if (n < 2)
        return 0;
    return (n * (n - 1)) / 2;
}

void solve()
{
    int n, k, x;
    cin >> n >> k;
    bool ques = false;
    for (int i = 0; i <= n; i++)
    {
        if (nc2(i) + nc2(n - i) == k)
        {
            x = i;
            ques = true;
            break;
        }
    }
    if (ques)
    {
        cout << "YES" << '\n';
        for (int i = 0; i < x; i++)
        {
            cout << 1 << " ";
        }
        for (int i = 0; i < n - x; i++)
        {
            cout << -1 << " ";
        }
    }
    else
    {
        cout << "NO";
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