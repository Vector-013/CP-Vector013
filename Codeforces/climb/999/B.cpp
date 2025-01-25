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
    int maxeql = -1;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] >= 2)
        {
            maxeql = max(maxeql, a[i]);
        }
    }
    vector<int> b;
    int cntm = 2;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxeql && cntm > 0)
            cntm--;
        else
            b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    int rng = 2 * maxeql - 1;
    for (int i = 0; i < b.size() - 1; i++)
    {
        if (b[i + 1] - b[i] <= rng)
        {
            cout << maxeql << " " << maxeql << " " << b[i] << " " << b[i + 1] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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