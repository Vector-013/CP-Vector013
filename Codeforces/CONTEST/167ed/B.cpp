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
    string s, z;
    cin >> s >> z;
    int ans = 0;
    int m = s.size(), n = z.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (auto c : s)
        {
            if (j < n && z[j] == c)
                j++;
        }
        ans = max(ans, j - i);
    }
    cout << -ans + n + m << '\n';
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