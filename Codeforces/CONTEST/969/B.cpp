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
    ll n, m, maxi = -linf;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxi = max(v[i], maxi);
    }
    int a, b;
    char c;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> a >> b;
        if (a <= maxi && b >= maxi)
        {
            if (c == '+')
                maxi++;
            else
                maxi--;
        }
        cout << maxi << " ";
    }
    cout << '\n';
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