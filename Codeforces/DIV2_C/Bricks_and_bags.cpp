#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
const int INF = 2e9;
typedef long long ll;
typedef long double ld;

void solve()
{
    int n, mini = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i < n - 1; i++)
    {
        mini = max(mini, max(2 * a[i + 1] - a[i] - a[0], a[n - 1] + a[i] - 2 * a[i - 1]));
    }
    cout << mini << '\n';
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