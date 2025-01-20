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
    map<ll, ll> mp, mp2;
    vector<pair<ll, ll>> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        b[i].second = a[i].first;
        mp[a[i].first] = i;
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].second;
        b[i].first = a[i].second;
        mp2[b[i].first] = i;
    }
    sort(a.begin(), a.end(), greater<pair<ll, ll>>());
    set<int> r;
    for (int i = 1; i < n; ++i)
        r.insert(a[i].second);
    ans[mp[a[0].first]] = 1;
    for (int i = 1; i < n; i++)
    {
        int rmax = *r.rbegin();
        ans[mp[a[i].first]] = (int)(rmax > a[0].second);
        r.erase(a[i].second);
    }
    r.clear();
    sort(b.begin(), b.end(), greater<pair<ll, ll>>());
    for (int i = 1; i < n; ++i)
        r.insert(b[i].second);
    ans[mp2[b[0].first]] = 1;
    for (int i = 1; i < n; i++)
    {
        int rmax = *r.rbegin();
        ans[mp2[b[i].first]] = (int)(rmax > b[0].second);
        r.erase(b[i].second);
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i];
    cout << '\n';
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