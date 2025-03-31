#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int M = 1e9 + 7;
#define int long long

int p[100005], pw[11][100005], cp[11][100005], c[11], s[11];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        p[i] = (p[i - 1] + a[i]) % M;

    for (int m = 0; m <= k; m++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (!m)
                pw[m][i] = 1;
            else
                pw[m][i] = (pw[m - 1][i] * p[i]) % M;
        }
        for (int i = 0; i <= n; i++)
            cp[m][i] = ((i ? cp[m][i - 1] : 0) + pw[m][i]) % M;
    }

    c[0] = 1;
    for (int m = 1; m <= k; m++)
        c[m] = c[m - 1] * (k - m + 1) / m;

    for (int m = 0; m <= k; m++)
        s[m] = (k - m) % 2 ? M - 1 : 1;

    int r = 0;
    for (int m = 0; m <= k; m++)
    {
        int e = k - m;
        int sm = 0;
        for (int i = 1; i <= n; i++)
            sm = (sm + pw[m][i] * (i ? cp[e][i - 1] : 0)) % M;
        r = (r + c[m] % M * s[m] % M * sm) % M;
    }
    cout << (r % M + M) % M << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}