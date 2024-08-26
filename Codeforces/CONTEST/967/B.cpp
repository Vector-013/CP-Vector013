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
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        if (i == (n + 1) / 2)
        {
            cout << i << '\n';
            return;
        }
        if (i % 4)
            cout << n + 1 - i << " " << i << " ";
        else
            cout << i << " " << n + 1 - i << " ";
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