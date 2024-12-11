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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int m;
    cin >> m;
    map<int, int> mp;
    bool last = false;
    vector<int> d(m);
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
        mp[d[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (mp[b[i]] > 0)
            {
                if (!last)
                    last = (b[i] == d[m - 1]) ? true : false;
                mp[b[i]]--;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            if (b[i] == d[m - 1])
                last = true;
        }
    }
    cout << (last ? "YES\n" : "NO\n");
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