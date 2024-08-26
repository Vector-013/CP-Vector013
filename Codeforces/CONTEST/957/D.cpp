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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int j = m;
    int w;
    bool log = 0;
    bool water = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || s[i - 1] == 'L')
        {
            if (i - 1 + m > n)
            {
                cout << "yes\n";
                return;
            }
            j = i + m;
            while (j > i)
            {
                if (s[j - 1] == 'L')
                {
                    i = j - 1;
                    log = 1;
                    break;
                }
                else
                    log = 0;
                j--;
            }

            if (!log)
            {
                j = i + m;
                while (j > i)
                {
                    if (s[j - 1] == 'W')
                    {
                        water = 1;
                        break;
                    }
                    j--;
                }
                if (!water)
                {
                    cout << "no\n";
                    return;
                }
                while (k)
                {
                    j++;
                    k--;
                    if (j == n)
                    {
                        cout << "yes\n";
                        return;
                    }
                    if (s[j - 1] == 'L')
                    {
                        i = j - 1;
                        break;
                    }
                    if (s[j - 1] == 'C')
                    {
                        cout << "no\n";
                        return;
                    }
                    if (k == 0)
                    {
                        cout << "npo\n";
                        return;
                    }
                }
            }
        }
        log = 0;
        water = 0;
    }
    cout << "no\n";
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