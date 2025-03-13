#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 998244353;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<vector<int>> z(n, vector<int>(30, 0));
    for (auto &x : a)
        cin >> x;
    vector<int> pre(n + 1);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] ^ a[i];

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
            z[i] = z[i - 1];
        z[i][__lg(a[i])] = i;

        for (int j = 28; j >= 0; j--)
            z[i][j] = max(z[i][j], z[i][j + 1]);
    }

    while (q--)
    {
        int x;
        cin >> x;
        int s = n - 1;
        while (s >= 0 && x > 0)
        {
            int msb = __lg(x);
            int pos = z[s][msb];
            x ^= pre[pos] ^ pre[s];
            s = pos;
            if (pos == -1 || a[pos] > x)
                break;
            x ^= a[pos];
            s--;
        }
        cout << n - s - 1 << ' ';
    }
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
