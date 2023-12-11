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
    vector<int> v(2 * n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = n; i < 2 * n; i++)
        v[i] = v[i - n];

    int dcnt = 1, icnt = 1;
    bool inc, dec;
    int pos;
    for (int i = 1; i < 2 * n; i++)
    {
        if (cnt == n)
        {
            flag = false;
            inc = true;
            pos = i;
            break;
        }
        if (v[i] >= v[i - 1])
            cnt++;
        else
            cnt = 1;
    }

    if (flag)
    {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;
    ans = n - pos;
    if (!inc)
        ans++;
    cout << ans << '\n';
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