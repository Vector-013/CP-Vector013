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
    int cn1 = 0, loc1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cn1 += (a[i] == 1);
        if (a[i] == 1)
            loc1 = i;
    }
    if (cn1 != 1)
    {
        cout << "NO\n";
        return;
    }
    rotate(a.begin(), a.begin() + loc1, a.end());
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > 1)
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