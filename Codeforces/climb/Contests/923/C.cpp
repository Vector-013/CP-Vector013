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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    set<int> s(a.begin(), a.end());
    set<int> s2(b.begin(), b.end());
    a.clear();
    b.clear();
    for (int x : s)
        a.push_back(x);
    for (int x : s2)
        b.push_back(x);
    map<int, int> cnt;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] <= k)
            cnt[a[i]] = 1;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] <= k)
            cnt[b[i]] += 2;
    }
    int cnta = 0, cntb = 0, both = 0;
    for (int i = 1; i <= k; i++)
    {
        if (cnt[i] == 1)
            cnta++;
        if (cnt[i] == 2)
            cntb++;
        if (cnt[i] == 3)
            both++;
    }
    if ((cnta + cntb + both) != k)
    {
        cout << "NO\n";
        return;
    }
    if ((cnta <= k / 2) && (cntb <= k / 2))
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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