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
    string s, z;
    cin >> n >> s >> z;
    if (s == z && s == string(n, 'x'))
    {
        cout << 0 << '\n';
        return;
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i - 1] == '.' && s[i + 1] == '.' && z[i - 1] == 'x' && z[i + 1] == 'x' && s[i] == '.' && z[i] == '.')
        {
            cnt++;
        }
        if (z[i - 1] == '.' && z[i + 1] == '.' && s[i - 1] == 'x' && s[i + 1] == 'x' && z[i] == '.' && s[i] == '.')
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return;
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