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
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto c : s)
    {
        mp[c]++;
    }
    char maxc;
    int maxn = 0;
    for (auto p : mp)
    {
        if (p.second > maxn)
        {
            maxn = p.second;
            maxc = p.first;
        }
    }
    char minc;
    int minn = inf;
    for (auto p : mp)
    {
        if (p.second < minn)
        {
            minn = p.second;
            minc = p.first;
        }
    }
    if (maxc == minc)
    {
        if (n == 1)
            cout << s << '\n';
        else
        {
            char a = s[0];
            bool y = false;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != a)
                {
                    s[i] = a;
                    cout << s << '\n';
                    y = true;
                    return;
                }
            }
            cout << s << '\n';
        }

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == minc)
        {
            s[i] = maxc;
            cout << s << '\n';
            return;
        }
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