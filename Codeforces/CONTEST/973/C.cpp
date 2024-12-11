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
ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}
void solve()
{
    string t = "";
    int n;
    cin >> n;
    string s;
    int a;
    int b = 1;
    while (t.length() < n)
    {
        if (b)
        {
            t += "0";
            cout << "? " << t << endl;
            cout.flush();
            cin >> a;
            if (a)
            {
                continue;
            }
            else
            {
                t.pop_back();
                t += "1";
                cout << "? " << t << endl;
                cout.flush();
                cin >> b;
                if (!b)
                    t.pop_back();
            }
        }
        if (!b)
        {
            t = "0" + t;
            cout << "? " << t << endl;
            cout.flush();
            cin >> a;
            if (a)
            {
                continue;
            }
            else
            {
                t[0] = '1';
                continue;
            }
        }
    }
    cout << "! " << t << endl;
    cout.flush();
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