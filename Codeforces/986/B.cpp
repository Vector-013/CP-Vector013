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
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    ll n, b, c;
    cin >> n >> b >> c;
    if (c >= n)
    {
        cout << n << '\n';
    }
    else
    {
        if (b > 0)
        {
                cout << n - (n - 1 - c) / b - 1 << '\n';
        }
        else if (n - 3 >= c)
            cout << "-1\n";
        else
            cout << n - 1 << '\n';
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