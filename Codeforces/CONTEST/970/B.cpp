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

bool isPerfectSquare(long long x)
{
    if (x >= 0)
    {

        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (!isPerfectSquare(n))
    {
        cout << "No\n";
        return;
    }
    else
    {
        int p;
        for (int i = 1; i < n; i++)
        {
            if (i * i == n)
            {
                p = i;
                break;
            }
        }
        string s1 = string(p, '1');
        string ex;
        string s2 = "1" + string(p - 2, '0') + "1";
        ex = s1;
        for (int i = 0; i < p - 2; i++)
        {
            ex += s2;
        }
        ex += s1;
        if (ex == s)
        {
            cout << "Yes\n";
            return;
        }
        else
        {
            cout << "No\n";
            return;
        }
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