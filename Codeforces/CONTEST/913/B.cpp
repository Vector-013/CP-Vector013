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
    string s;
    cin >> s;
    int n = s.size();
    int b = 0, B = 0;
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'b')
        {
            b++;
            continue;
        }
        if (s[i] == 'B')
        {
            B++;
            continue;
        }

        if (b > 0 && s[i] > 92)
        {
            b--;
            continue;
        }
        else if (B > 0 && s[i] < 92)
        {
            B--;
            continue;
        }
        else
        {
            ans.append(1, s[i]);
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
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