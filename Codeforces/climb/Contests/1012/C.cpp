#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int m = 5 * (sqrtl(n) + 1);
    vector<int> s;
    for (int i = 1; i <= m + 2; i += 3)
        s.push_back(i);

    set<tuple<int, int, int>> z0, z1;
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 0; j < s.size(); ++j)
        {
            z1.emplace(s[i] + s[j] - 1, s[i], s[j]);
            z1.emplace(s[i] + s[j], s[i] + 1, s[j]);
            z1.emplace(s[i] + s[j], s[i], s[j] + 1);
            z1.emplace(s[i] + s[j] + 3, s[i] + 1, s[j] + 1);
            z0.emplace(s[i] + s[j] - 1, s[i], s[j]);
        }
    }

    for (auto x : v)
    {
        if (x)
        {
            auto [a, b, c] = *z1.begin();
            z1.erase(z1.begin());
            auto it = z0.begin();
            if (*it == make_tuple(a, b, c))
                z0.erase(it);

            cout << b << " " << c << '\n';
        }
        else
        {
            auto [a, b, c] = *z0.begin();
            z0.erase(z0.begin());
            auto it = z1.find({a, b, c});
            if (it != z1.end())
                z1.erase(it);
            cout << b << " " << c << '\n';
        }
        // for (auto [a, b, c] : z0)
        //     cout << a << " " << b << " " << c << '\n';
        // for (auto [a, b, c] : z1)
        //     cout << a << " " << b << " " << c << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}