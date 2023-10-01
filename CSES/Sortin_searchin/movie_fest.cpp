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
bool pair_sec_sort(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), pair_sec_sort);
    vector<int> f(n), s(n);
    for (int i = 0; i < n; i++)
    {
        f[i] = v[i].first;
        s[i] = v[i].second;
    }
    int i = 0, j = 0, cnt = 1;
    while (1)
    {
        while (i < n && f[i] < s[j])
        {
            i++;
        }
        if (i == n)
        {
            break;
        }
        j = i;
        cnt++;
    }
    cout << cnt << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    solve();
}