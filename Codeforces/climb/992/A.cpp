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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool q = 0;
    for (int i = 0; i < n; i++)
    {
        q = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (abs(a[j] - a[i]) % k == 0)
                {
                    q = 1;
                    break;
                }
            }
            else
                continue;
        }
        if (!q)
        {
            cout << "YES\n";
            cout << i + 1 << '\n';
            return;
        }
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
