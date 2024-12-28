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
    string q = string(n, '0');
    map<char, int> cnt;
    for (char c : s)
        cnt[c]++;
    int cn = 0;
    for (auto [c, x] : cnt)
        if (x & 1)
            cn++;
    if (cn == 0)
    {
        sort(s.begin(), s.end());
        for (int i = 0; i < n; i += 2)
        {
            q[i] = q[n - i - 1] = s[i];
        }
        cout << q << '\n';
        return;
    }
    if (cn == 1)
    {
        // make lexicographically smallest palindrome
        char odd;
        for (auto [c, x] : cnt)
            if (x & 1)
                odd = c;
        cnt[odd]--;
        for (auto [c, x] : cnt)
            for (int i = 0; i < x / 2; i++)
                cout << c;
        cout << odd;
        string rev = "";
        for (auto [c, x] : cnt)
            for (int i = 0; i < x / 2; i++)
            {
                rev += c;
            }
        reverse(rev.begin(), rev.end());
        cout << rev << '\n';
    }
    else
    {
        sort(s.begin(), s.end());
        int i = 0, j = n - 1, x = 0;
        while (x < n - 1 && s[x] == s[x + 1])
        {
            q[i] = q[j] = s[x];
            i++, j--;
            x += 2;
        }
        q[i] = s[x + 1];
        q[j] = s[x];
        x += 2;
        i++, j--;
        while (i <= j)
        {
            q[i] = s[x];
            x++;
            i++;
        }
        cout << q << '\n';
    }
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