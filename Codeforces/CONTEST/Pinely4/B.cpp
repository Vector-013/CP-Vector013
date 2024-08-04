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
    vector<int> b(n);
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    b[0] = a[0];
    b[n - 1] = a[n - 2];
    for (int i = 1; i < n - 1; i++)
    {
        b[i] = a[i] | a[i - 1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != (b[i] & b[i + 1]))
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
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