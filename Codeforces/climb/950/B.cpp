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
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    f = v[f - 1];
    sort(v.begin(), v.end(), greater());
    int loc = -1;
    int last = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == f && loc == -1)
        {
            loc = i;
        }
        if (v[i] == f)
        {
            last = i;
        }
    }
    if (loc == -1)
    {
        cout << "NO\n";
        return;
    }
    loc++;
    last++;
    if (k >= last)
    {
        cout << "YES\n";
        return;
    }
    if (k < loc)
    {
        cout << "NO\n";
        return;
    }
    cout << "MAYBE\n";
    return;
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