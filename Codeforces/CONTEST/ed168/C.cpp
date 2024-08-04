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
    int i = 1;
    int cur = i;
    ll sum = 0;
    while (i <= n)
    {
        if (s[i - 1] == '(')
            sum++;
        if (s[i - 1] == ')')
        {
            sum += i - cur;
            cur = i + 1;
        }
        i++;
    }
    cout << sum << '\n';
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