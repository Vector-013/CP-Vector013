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
    int n, dif;
    cin >> n;
    vector<int> v(n);
    // map<int,int> f;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // f[v[i]]++;
    }
    v.pb(0);
    int cfeq = 0, j;
    vector<int> f;
    vector<int> h;
    for (int i = 0; i < n; i++)
    {
        j = i;
        cfeq = 0;
        while (j < n && v[j] == v[i])
        {
            cfeq++;
            j++;
        }
        i = j - 1;
        f.pb(cfeq);
        h.pb(v[i] - v[i + 1]);
    }
    if (f.size() != h.size())
    {
        cout << "NO" << '\n';
        return;
    }
    else
    {
        for (int i = 0; i < f.size(); i++)
        {
            if (f[i] == h[f.size() - 1 - i])
                continue;
            else
            {
                cout << "NO" << '\n';
                return;
            }
        }
        cout << "YES" << '\n';
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