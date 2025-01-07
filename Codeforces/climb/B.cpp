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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), f;
    map<int, int> mp;
    int mxidx;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int mx = 0;
    for (auto x : mp)
        f.push_back(x.second);
    sort(f.begin(), f.end());
    ll sum = 0;
    int bad = f.size() - 1;
    for (int i = 0; i < f.size(); ++i)
    {
        if (sum + f[i] > k)
        {
            bad = i;
            break;
        }
        sum += f[i];
    }
    cout << f.size() - bad << '\n';
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