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
    string s, w;
    cin >> s >> w;
    int n = s.size(), m = w.size();
    map<char, int> mp1, mp2;
    for (char c = 'a'; c <= 'z'; c++)
        mp1[c] = -1;
    for (char c = 'a'; c <= 'z'; c++)
        mp2[c] = -1;

    for (int i = 1; i < n; i++)
    {
        if (mp1[s[i]] == -1 || mp1[s[i]] > i)
            mp1[s[i]] = i;
    }
    for (int i = 0; i < m - 1; i++)
    {
        if (mp2[w[i]] == -1 || mp2[w[i]] < i)
            mp2[w[i]] = i;
    }
    int p1, p2;
    int dif = 1e9;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (mp1[c] != -1 && mp2[c] != -1)
        {
            if (mp1[c] + m - mp2[c] < dif)
            {
                // cout << c << '\n';
                dif = mp1[c] + m - mp2[c];
                p1 = mp1[c];
                p2 = mp2[c];
            }
        }
    }
    if (dif == 1e9)
    {
        cout << -1 << '\n';
        return;
    }
    // cout << p1 << ' ' << p2 << '\n';
    cout << s.substr(0, p1) + w.substr(p2) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}