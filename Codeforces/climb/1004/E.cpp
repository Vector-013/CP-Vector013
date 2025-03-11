#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int cnt0 = 0;
    vector<int> a(n);
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cnt0 += (a[i] == 0);
        if (a[i] != 0)
            v.push_back(a[i]);
        else if ((a[i] == 0) && (cnt0 == 1))
            v.push_back(a[i]);
    }
    // for (auto x : v)
    //     cout << x << ' ';
    // cout << '\n';
    if (cnt0 == 0)
    {
        cout << n << '\n';
        return;
    }
    int c = v.size();
    int ans = n - cnt0;

    vector<int> premin(c), sufmex(c);
    set<int> s;
    premin[0] = v[0];
    for (int i = 1; i < c; ++i)
    {
        premin[i] = min(premin[i - 1], v[i]);
    }

    for (int i = 0; i < c; ++i)
        s.insert(i);
    for (int i = c - 1; i >= 0; i--)
    {
        if (s.find(v[i]) != s.end())
            s.erase(s.find(v[i]));
        sufmex[i] = *s.begin();
    }

    for (int i = 0; i < c - 1; ++i)
    {
        if (premin[i] < sufmex[i + 1])
            break;
        else if (i == c - 2)
            ans++;
    }
    if (ans == 0)
        ans++;
    cout << ans << '\n';
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
