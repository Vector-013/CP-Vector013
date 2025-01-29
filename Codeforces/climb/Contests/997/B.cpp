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
    vector<string> s(n);
    vector<vector<int>> bak(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[i][j] == '0')
                bak[i].push_back(j);
            else
                bak[j].push_back(i);
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[n - 1 - bak[i].size()] = i + 1;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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