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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    int s1 = 0, s2 = 0;
    for (auto p : v)
    {
        if (p.first != p.second)
        {
            if (p.first > p.second)
                s1 += p.first;
            else
                s2 += p.second;
        }
    }
    for (auto p : v)
    {
        if (p.first == p.second)
        {
            if (p.first == 1)
            {
                if (s1 >= s2)
                    s2++;
                else
                    s1++;
            }
            else if (p.second == -1)
            {
                if (s1 >= s2)
                    s1--;
                else
                    s2--;
            }
        }
    }
    cout << min(s1, s2) << '\n';
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