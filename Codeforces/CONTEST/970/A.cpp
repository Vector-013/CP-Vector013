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
    int a, b;
    cin >> a >> b;
    if ((a % 2 == 0) && (b % 2 == 0))
    {
        cout << "yes\n";
        return;
    }
    else if ((a % 2 == 1))
    {
        cout << "no\n";
        return;
    }
    else
    {
        if (a != 0)
        {
            cout << "yes\n";
            return;
        }
        else
        {
            cout << "no\n";
            return;
        }
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