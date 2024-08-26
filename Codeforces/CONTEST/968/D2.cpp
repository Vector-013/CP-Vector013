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
    ll n, m;
    cin >> n >> m;
    set<ll> s;
    ll p;
    ll a, l;
    ll mex1 = -linf;
    ll mex2 = -linf;
    ll mmex2 = -linf;
    bool t = 0;
    while (n)
    {
        mex1 = -linf;
        mex2 = -linf;
        cin >> l;
        set<ll> s;
        for (int i = 0; i < l; i++)
        {
            cin >> a;
            s.insert(a);
        }
        mex1 = 0;
        while (s.count(mex1))
            ++mex1;
        mex2 = 0;
        s.insert(mex1);
        while (s.count(mex2))
            ++mex2;
        mmex2 = max(mmex2, mex2);

        // cout << mex2 << '\n';
        n--;
    }
    mex2 = mmex2;
    if (m > mex2)
        cout << (m * (m + 1) / 2) + (mex2 * (mex2 + 1) / 2) << '\n';
    else
        cout << (m + 1) * mex2 << '\n';
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