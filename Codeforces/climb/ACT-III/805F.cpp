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
    multiset<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (x % 2 == 0)
            x /= 2;
        a.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
    }
    while (!b.empty())
    {
        int x = *b.begin();
        while (x)
        {
            if (a.count(x))
            {
                a.erase(a.find(x));
                b.erase(b.begin());
                break;
            }
            x /= 2;
            if (x == 0)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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