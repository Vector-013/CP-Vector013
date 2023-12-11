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
    string n(1, s[1]);
    int k = stoi(n);

    for (int i = 1; i <= 8; i++)
    {
        if (i != k)
            cout << s[0] << i << '\n';
    }

    char c;
    for (int i = 97; i < 105; i++)
    {
        c = i;
        if (c != s[0])
            cout << c << k << '\n';
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