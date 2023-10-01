#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
const int INF = 2e9;
#define make_pair
#define pb push_back
#define pop pop_back
typedef long long ll;
#define j ceil((6.0 * n) / i)

void solve()
{
    ll n, a, b, minprod;
    cin >> n >> a >> b;
    if (a * b >= 6 * n)
    {
        cout << a * b << '\n';
        cout << a << " " << b << '\n';
    }
    else
    {
        ll mini = min(a, b);
        ll maxi = max(a, b);
        minprod = 9e18;
        for (ll i = mini; i < ceil(sqrtl(6.0 * n)); i++)
        {
            ll k = (ll)j;
            if ((i * k) < minprod && k >= maxi && maxi <= max(i, k) && mini <= min(i, k))
            {
                minprod = i * k;

                if (a < b)
                {
                    a = i;
                    b = k;
                }
                else
                {
                    b = i;
                    a = k;
                }
            }
        }
        cout << a * b << '\n';
        cout << a << " " << b << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}