#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n), w(n);
    map<pair<int, int>, int> cnt, idx;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        cnt[v[i]]++;
        w[i] = {-v[i].second, -v[i].first};
        idx[v[i]] = i;
        idx[w[i]] = i;
    }
    auto b = v;

    auto compare = [](pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    };
    sort(v.begin(), v.end(), compare);
    sort(w.begin(), w.end(), compare);

    auto get = [&](vector<int> &sum, vector<pair<int, int>> &z, bool flag) -> void
    {
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            auto it = s.lower_bound(z[i].second);
            if (it == s.end())
                sum[idx[z[i]]] = 0;
            else
            {
                sum[idx[z[i]]] += *it - z[i].second;
            }
            s.insert(z[i].second);
        }
    };

    vector<int> sum(n, 0);
    get(sum, v, 0);
    get(sum, w, 1);

    for (int i = 0; i < n; ++i)
        cout << (cnt[b[i]]<=1 ? sum[i] : 0) << "\n";
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
