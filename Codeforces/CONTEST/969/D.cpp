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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    string s;
    cin >> s;
    int leaf_cnt1 = 0;
    int leaf_cnt0 = 0;
    int num_leaf = 0;
    int unmarked = 0;
    int unmarked_middle = 0;

    auto leaf_majority = [&](auto self, int u, int p) -> void
    {
        if (g[u].size() == 1 && u != 0)
        {
            num_leaf++;
            if (s[u] == '1')
                leaf_cnt1++;
            else if (s[u] == '0')
                leaf_cnt0++;
            else if (s[u] == '?')
                unmarked++;
            return;
        }
        for (int v : g[u])
        {
            if (v == p)
                continue;
            if (g[v].size() > 1 && v != 0)
            {
                if (s[v] == '?')
                    unmarked_middle++;
            }
            self(self, v, u);
        }
    };
    leaf_majority(leaf_majority, 0, -1);

    int ans;

    if (s[0] == '?')
    {
        ans = unmarked / 2 + max(leaf_cnt1, leaf_cnt0);
        if ((unmarked % 2) && (unmarked_middle % 2) && (leaf_cnt0 == leaf_cnt1))
            ans++;
    }
    else if (s[0] == '1')
    {
        ans = (unmarked + 1) / 2 + leaf_cnt0;
    }
    else if (s[0] == '0')
    {
        ans = (unmarked + 1) / 2 + leaf_cnt1;
    }

    cout << ans << '\n';
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