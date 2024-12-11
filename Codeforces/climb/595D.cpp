#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> L(2 << 17);
    set<pair<int, int>> s;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l;
        L[l].push_back({r, i});
    }
    for (int i = 0; i < 2 << 17; i++)
    {
        while (!s.empty() && s.begin()->first <= i)
        {
            s.erase(s.begin());
        }
        for (auto p : L[i])
        {
            s.insert(p);
        }
        while (s.size() > k)
        {
            auto it = s.end();
            it--;
            ans.push_back(it->second);
            s.erase(it);
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x + 1 << (x == ans.back() ? '\n' : ' ');
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
        solve();
}