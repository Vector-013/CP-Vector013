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
    map<int, pair<int, vector<int>>> cnt;
    map<char, int> cnt1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]].first++;
        cnt[a[i]].second.push_back(i);
    }
    char cur = 'a';
    string ans = string(n, '?');
    for (auto &[i, v] : cnt)
    {
        int x = v.first;
        for (int j = 0; j < x; ++j)
        {
            ans[v.second[j]] = cur;
            cur++;
        }
        cur = 'a';
    }
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