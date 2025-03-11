#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &di : d)
        cin >> di;
    set<int> alive, die;
    for (int i = 0; i < n; i++)
        alive.insert(i);
    for (int i = 0; i < n; i += 1)
    {
        if ((i ? a[i - 1] : 0) + (i + 1 < n ? a[i + 1] : 0) > d[i])
        {
            die.insert(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << die.size() << " ";
        set<int> to_die;
        for (int x : die)
        {
            alive.erase(x);
        }
        auto check = [&](auto it)
        {
            if ((it != alive.begin() ? a[*prev(it)] : 0) +
                    (next(it) != alive.end() ? a[*next(it)] : 0) >
                d[*it])
            {
                to_die.insert(*it);
            }
        };
        for (int x : die)
        {
            auto it = alive.lower_bound(x);
            if (it != alive.end())
            {
                check(it);
            };
            if (it != alive.begin())
            {
                check(prev(it));
            };
        }
        to_die.swap(die);
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
