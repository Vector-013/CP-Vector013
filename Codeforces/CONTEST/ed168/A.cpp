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
    char c = 'a';
    if (s.length() == 1)
    {
        if (s[0] == c)
            c++;
        cout << s << c << '\n';
        return;
    }
    if (s[0] == s[1])
    {
        if (s[0] != c)
        {
            cout << s[0] << c << s.substr(1) << '\n';
            return;
        }
        else
        {
            cout << s[0] << ++c << s.substr(1) << '\n';
            return;
        }
    }
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            if (s[i] != c)
            {
                cout << s.substr(0, i) << c << s.substr(i) << '\n';
                return;
            }
            else
            {
                cout << s.substr(0, i) << ++c << s.substr(i) << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (c != s[0] && c != s[1])
            break;
        c++;
    }
    cout << s[0] << c << s.substr(1) << '\n';
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