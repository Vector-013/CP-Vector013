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
    if (s[0] == '1')
        cout << 13 << '\n';
    if (s[0] == '2')
        cout << 23 << '\n';
    if (s[0] == '3')
        cout << 31 << '\n';
    if (s[0] == '4')
        cout << 41 << '\n';
    if (s[0] == '5')
        cout << 53 << '\n';
    if (s[0] == '6')
        cout << 61 << '\n';
    if (s[0] == '7')
        cout << 71 << '\n';
    if (s[0] == '8')
        cout << 83 << '\n';
    if (s[0] == '9')
        cout << 97 << '\n';
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