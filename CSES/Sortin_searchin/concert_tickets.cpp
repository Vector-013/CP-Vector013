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
    int n, m, a;
    cin >> n >> m;
    multiset<int> t;
    vector<int> p(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        t.insert(a);
    }
    for (int i = 0; i < m; i++)
        cin >> p[i];
    for (int i = 0; i < m; i++)
    {
        if (t.size() == 0)
        {
            cout << -1 << '\n';
            continue;
        }

        auto ptr = t.upper_bound(p[i]);
        if (ptr == t.begin())
        {
            cout << -1 << '\n';
            continue;
        }
        --ptr;
        cout << *ptr << '\n';
        t.erase(ptr);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}