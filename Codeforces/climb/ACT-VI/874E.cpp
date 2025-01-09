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
    int n;
    cin >> n;
    DSU dsu(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        dsu.merge(i, a[i]);
    }
    set<int> s1;

    for (int i = 0; i < n; i++)
        s1.insert(dsu.find(i));
    int maxi = s1.size();
    map<int, vector<int>> ds;
    for (int i = 0; i < n; i++)
        ds[dsu.find(i)].push_back(i);
    int str = 0, cicl = 0;
    for (auto [q, x] : ds)
    {
        set<int> s2;
        for (auto y : x)
            s2.insert(a[y]);
        if (s2.size() != x.size() || dsu.size(x[0]) == 2 || dsu.size(x[0]) == 1)
            str++;
        else
            cicl++;
    }
    int mini = cicl + (str > 0);
    cout << mini << " " << maxi << '\n';
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