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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> a(n, 0);
    a[v[0] - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        if ((v[i] - 2 >= 0 && a[v[i] - 2] == 0) && (v[i] < n && a[v[i]] == 0))
        {
            cout << "NO\n";
            return;
        }
        if ((v[i] == 1 && a[v[i]] == 0))
        {
            cout << "NO\n";
            return;
        }
        if ((v[i] == n && a[v[i] - 2] == 0))
        {
            cout << "NO\n";
            return;
        }
        a[v[i] - 1] = 1;
    }
    cout << "YES\n";
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