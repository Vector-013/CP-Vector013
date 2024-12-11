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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int loc = -1;
    int cur, prev=-inf;
    for (int i = 0; i < n - 1; i++)
    {
        cur = __gcd(a[i], a[i + 1]);
        if (prev > cur)
        {
            loc = i;
            break;
        }
        prev = cur;
    }
    if (loc == -1)
    {
        cout << "YES\n";
        return;
    }
    auto a1 = a, a2 = a, a3 = a;
    a1.erase(a1.begin() + loc);
    if (loc + 1 < n)
        a2.erase(a2.begin() + loc + 1);
    if (loc - 1 >= 0)
        a3.erase(a3.begin() + loc - 1);
    auto check = [&](vector<int> &b) -> bool
    {
        int cur, prev = __gcd(b[0], b[1]);

        for (int i = 1; i < b.size() - 1; i++)
        {
            cur = __gcd(b[i], b[i + 1]);
            if (prev > cur)
            {
                return 0;
            }
            prev = cur;
        }
        return 1;
    };
    bool res = check(a1) || check(a2) || check(a3);
    (res) ? cout << "YES\n" : cout << "NO\n";
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