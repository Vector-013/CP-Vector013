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
    vector<int> v(n), a(n);
    map<int, int> pos1, pos2;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        pos1[v[i]] = i;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        pos2[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int x = v[i];
        int j = pos2[x];
        for (int k = j - 1; k >= 0; k--)
        {
            ans.push_back({a[j], a[k]});
        }
        for (int k = 0; k < j; k++)
        {
            ans.push_back({a[k], a[j]});
        }
        for (int k = j + 1; k <= i; k++)
        {
            ans.push_back({a[k], x});
            swap(a[k], a[k - 1]);

            pos2[a[k - 1]] = k - 1;
            pos2[x] = k;
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}