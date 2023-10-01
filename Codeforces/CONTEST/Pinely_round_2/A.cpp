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
    int n, a, q, p = 0, neg = 0, cnt = 0;
    string s;
    bool y = 0, no = 0;
    cin >> n >> a >> q;
    cin >> s;
    if (n == a)
    {
        cout << "YES" << '\n';
        return;
    }
    for (int i = 0; i < q; i++)
    {

        if (no && s[i] == '+')
            p++;
        if (s[i] == '-')
        {
            neg++;
            no = 1;
        }
        if (!no)
            cnt++;
        if (a + cnt >= n)
        {
            cout << "YES" << '\n';
            return;
        }
        if (a + cnt + p - neg >= n)
        {
            cout << "YES" << '\n';
            return;
        }
        if (a + cnt + p - neg >= n)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    // cout << p << " " << neg << " " << cnt << '\n';

    if (a + cnt + p - neg >= n)
    {
        cout << "YES" << '\n';
        return;
    }
    if (a + cnt + p >= n)
    {
        cout << "MAYBE" << '\n';
        return;
    }
    else
    {
        cout << "NO" << '\n';
        return;
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