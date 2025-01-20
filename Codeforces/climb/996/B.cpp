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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    int cnt = 0;
    int dif = 0;
    int loc = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first < v[i].second)
        {
            cnt++;
            loc = i;
            dif = v[i].second - v[i].first;
        }
    }
    if (cnt > 1)
    {
        cout << "NO\n";
        return;
    }
    if (cnt == 0)
    {
        cout << "YES\n";
        return;
    }
    bool f = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i == loc)
            continue;
        if ((v[i].first - v[i].second) < dif)
            f = 0;
    }
    cout << (f ? "YES\n" : "NO\n");
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