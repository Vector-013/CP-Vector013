#include <bits/stdc++.h>
using namespace std;
int mex(set<int> s)
{
    int res = 0;
    while (s.count(res))
        res++;
    return res;
};
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<int> ans(n);
    vector<set<int>> frnd(n);
    frnd[x].insert(y);
    frnd[y].insert(x);
    frnd[0].insert(n - 1);
    frnd[n - 1].insert(0);
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
            frnd[i].insert(i + 1);
        if (i > 0)
            frnd[i].insert(i - 1);
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.clear();
        for (auto it : frnd[i])
        {
            if (ans[it] == -1)
                continue;
            s.insert(ans[it]);
        }
        ans[i] = mex(s);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}