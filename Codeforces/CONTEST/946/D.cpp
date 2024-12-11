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

constexpr string t = "EWNS";
void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> vec[4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[j] == t[i])
            {
                vec[i].push_back(j);
            }
        }
    }
    if ((vec[0].size() + vec[1].size()) % 2 || (vec[2].size() + vec[3].size()) % 2)
    {
        cout << "NO\n";
        return;
    }

    string ans(n, 'R');
    for (int i = 0; i < 4; i += 2)
    {
        if (vec[i].size() < vec[i + 1].size())
        {
            swap(vec[i], vec[i + 1]);
        }
        for (int j = 0; j < vec[i].size() + vec[i + 1].size(); j++)
        {
            int t = (j % 2) ^ (i == 0) ^ (j >= vec[i].size());
            int p = j < vec[i].size() ? vec[i][j] : vec[i + 1][j - vec[i].size()];
            if (t)
            {
                ans[p] = 'H';
            }
        }
    }
    int cnt = count(ans.begin(), ans.end(), 'R');
    if (cnt == 0 || cnt == n)
    {
        cout << "NO\n";
        return;
    }
    cout << ans << "\n";
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