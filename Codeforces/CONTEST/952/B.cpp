#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
    int n;
    cin >> n;
    int x = -inf;
    int k;
    for (int i = 2; i <= n; i++)
    {
        if ((((i * (n / i) * (n / i + 1)) / 2) >= x))
        {
            k = i;
            x = ((i * (n / i) * (n / i + 1)) / 2);
        }
    }
    cout << k << '\n';
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