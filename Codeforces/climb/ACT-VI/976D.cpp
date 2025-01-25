#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

struct DSU
{
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m), d(m), k(m), s(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> d[i] >> k[i];
        a[i]--;
    }

    DSU dsu(n);
    int ans = n;
    for (int dd = 1; dd <= 10; ++dd)
    {
        s.assign(n, 0);
        for (int i = 0; i < m; i++)
        {
            if (d[i] != dd)
                continue;
            s[a[i]]++;
            s[a[i] + k[i] * dd]--;
        }
        for (int i = dd; i < n; i++)
            s[i] += s[i - dd];

        for (int i = 0; i < n; ++i)
        {
            if (s[i] > 0)
                ans -= dsu.merge(i, i + dd);
        }
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