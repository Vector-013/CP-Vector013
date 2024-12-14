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
    string s;
    cin >> n >> s;
    vector<int> l(n + 1, 0), r(n + 1, 0);
    l[1] = (s[0] == 'L');
    for (int i = 2; i <= n; i++)
    {
        if (s[i - 1] == 'L' && s[i - 2] == 'R')
            l[i] = l[i - 2] + 2;
        else if (s[i - 1] == 'L')
            l[i] = 1;
        else
            l[i] = 0;
    }
    r[n - 1] = (s[n - 1] == 'R');
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
            r[i] = r[i + 2] + 2;
        else if (s[i] == 'R')
            r[i] = 1;
        else
            r[i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        cout << l[i] + r[i] + 1 << " ";
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