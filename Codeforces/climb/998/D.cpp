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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto b = a;
    bool b1 = 0, b2 = 0;
    for (int i = 1; i < n; i++)
    {
        int cur = min(a[i], a[i - 1]);
        a[i] -= cur;
        a[i - 1] -= cur;
        if (a[i - 1] > a[i])
        {
            b1 = 1;
            break;
        }
    }
    if (!b1)
    {
        cout << "YES\n";
        return;
    }
    int loc = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i - 1] > b[i])
            loc = i;
    }
    for (int i = loc; i >= 1; i--)
    {
        int cur = min(b[i], b[i - 1]);
        b[i] -= cur;
        b[i - 1] -= cur;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] > b[i + 1])
        {
            cout << "NO\n";
            return;
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