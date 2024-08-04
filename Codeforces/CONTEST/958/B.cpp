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
    string s;
    cin >> s;
    if (s[0] == '1' && s[n - 1] == '1')
    {
        cout << "YES" << '\n';
        return;
    }
    if (s.size() == 1)
    {
        if (s[0] == '1')
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        return;
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            a++;
        else if (i > 0 && s[i - 1] == '1')
            b++;
        else if (i == 0)
            b++;
    }
    if (a > b)
    {
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
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