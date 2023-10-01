#include <iostream>
#include <vector>
#include <set>
using namespace std;
void solve()
{
    int m, n, ele;
    cin >> m;
    vector<vector<int>> v(m);
    set<int> s;
    vector<int> f(m);
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        v[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j]; // access to daywise participants possible
        }
    }
    for (int i = m - 1; i >= 0; i--) // traverse backwrd
    {
        ele = -1;
        for (auto j : v[i])
        {
            if (s.count(j) == 0)
            {
                ele = j;
                s.insert(j);
            }
        }
        if (ele == -1)
        {
            cout << ele << "\n";
            return;
        }

        f[i] = ele;
    }
    for (auto k : f)
    {
        cout << k << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }
}