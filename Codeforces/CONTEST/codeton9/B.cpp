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
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            cout << s[i] << s[i] << '\n';
            return;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i] != s[i - 2])
        {
            cout << s[i - 2] << s[i - 1] << s[i] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}