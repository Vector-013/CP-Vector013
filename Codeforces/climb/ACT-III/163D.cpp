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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int x = n; x >= 1; x--)
    {
        if (x & 1)
            continue;
        int l = 0;
        int r = x - 1;
        int m = r / 2;
        int cur = 0;
        int mid = (l + r) / 2;
        for (int i = 0; i <= m; i++)
        {
            if (s[i] == '?' || s[mid + i + 1] == '?' || s[i] == s[mid + i + 1])
            {
                cur++;
            }
        }
        if (cur == m + 1)
        {
            ans = 2 * (m + 1);
            break;
        }

        for (int l = 1; l <= n - x; l++)
        {
            cur -= (s[l - 1] == '?' || s[l - 1] == s[mid + l] || s[mid + l] == '?');
            int r = l + x - 1;
            int mid = (l + r) / 2;
            cur += (s[r] == '?' || s[mid] == '?' || s[r] == s[mid]);
            if (cur == m + 1)
            {
                ans = 2 * (m + 1);
                break;
            }
        }
        if (cur == m + 1)
        {
            ans = 2 * (m + 1);
            break;
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