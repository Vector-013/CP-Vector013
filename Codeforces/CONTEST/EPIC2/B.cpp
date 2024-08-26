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
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    bool z = 1, x = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            z = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[n - 1 - i])
        {
            x = 0;
        }
    }
    if (x || z)
    {
        cout << "Bob\n";
        return;
    }
    cout << "Alice\n";
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