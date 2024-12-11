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
    string s, r;
    int n;
    int cnt = 0;
    cin >> n >> s >> r;
    for (int i = 0; i < n; i++)
        (s[i] == '1') ? cnt++ : cnt--;

    for (int i = n; i >= 2; i--)
    {
        if (abs(cnt) == i)
        {
            cout << "NO\n";
            return;
        }
        (r[n - i] == '1') ? cnt++ : cnt--;
    }
    cout << "YES\n";
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