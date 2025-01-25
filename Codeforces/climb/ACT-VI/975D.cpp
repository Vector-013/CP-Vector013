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
    vector<int> l(n, n), r(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    int ml = n, mr = -1;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++)
    {
        ml = min(ml, l[i]);
        mr = max(mr, r[i]);
        if (mr <= ml + i)
        {
            int x = max(0, mr - i);
            int y = min(n - 1, ml + i);
            cnt[x]++;
            if (y + 1 < n)
                cnt[y + 1]--;
        }
    }
    for (int i = 1; i < n; i++)
        cnt[i] += cnt[i - 1];
    cout << count(cnt.begin(), cnt.end(), n) << '\n';
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