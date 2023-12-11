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
    string s;
    cin >> n >> s;
    sort(s.begin(), s.end());
    int cnt = 1, maxi = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
            maxi = max(cnt, maxi);
        }
        else
        {
            cnt = 1;
        }
    }

    if (n & 1)
    {
        if (maxi <= (n / 2) + 1)
        {
            cout << 1 << '\n';
            return;
        }
        else
        {
            cout << 2 * maxi - n << '\n';
            return;
        }
    }
    else
    {
        if (maxi <= n / 2)
        {
            cout << 0 << '\n';
            return;
        }
        else
        {
            cout << 2 * maxi - n << '\n';
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