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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int p = inf;
    char cur = s[0];
    char last = s[n - 1];
    int lack = 0;
    for (int i = n - 1; i >= n - k; i--)
    {
        if (s[i] == last)
            lack++;
        else
            break;
    }
    lack = k - lack;
    int pos = 0;
    for (int i = 0; i < n;)
    {
        int cnt = k;
        if (i > 0 && s[i - 1] != s[n - 1])
            pos = i;
        while (cnt--)
        {
            if (s[i] == cur)
                i++;
            else
            {
                p = i;
                break;
            }
        }
        if (p != inf)
            break;
        cur = (cur == '0' ? '1' : '0');
    }
    if (p == inf)
    {
        cout << n << '\n';
        return;
    }
    p = pos + lack;
    if (p >= n)
    {
        cout << -1 << '\n';
        return;
    }
    string t = s.substr(p);
    for (int i = p - 1; i >= 0; i--)
    {
        t += s[i];
    }
    bool sane = 1;
    cur = t[0];
    for (int i = 0; i < n;)
    {
        int cnt = k;
        while (cnt--)
        {
            if (t[i] == cur)
                i++;
            else
            {
                sane = 0;
                break;
            }
        }
        if (!sane)
            break;
        cur = (cur == '0' ? '1' : '0');
    }
    if (sane)
        cout << p << '\n';
    else
        cout << -1 << '\n';
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