#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s == string(n, '0') || s == string(n, '1'))
    {
        cout << n << '\n';
        return;
    }
    for (int k = n - 1; k > 1; k--)
    {
        auto w = s;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i <= n - k; i++)
        {
            pre[i + 1] += pre[i];
            if ((s[i] == '1' && pre[i + 1] % 2) || (s[i] == '0' && pre[i + 1] % 2 == 0))
            {
                if (i + k < n)
                    pre[i + k + 1]--;
                pre[i + 1]++;
            }
        }
        for (int i = n - k + 1; i < n; i++)
        {
            pre[i + 1] += pre[i];
            if ((s[i] == '1' && pre[i + 1] % 2) || (s[i] == '0' && pre[i + 1] % 2 == 0))
            {
                break;
            }
            if (i == n - 1)
            {
                cout << k << '\n';
                return;
            }
        }
    }
    cout << "1\n";
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