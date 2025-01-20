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
    map<char, char> final;
    for (char c = 'a'; c <= 'z'; c++)
    {
        final[c] = c;
    }
    int cur = -1;
    char maxi = 'a';
    vector<char> ms(n);

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, s[i]);
        ms[i] = maxi;
    }
    for (int i = 0; i < n; ++i)
    {
        if (ms[i] - 'a' <= k)
        {
            cur = i;
        }
        else
            break;
    }
    if (cur != -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] <= ms[cur])
                s[i] = 'a';
        }

        k -= ms[cur] - 'a';
    }
    if (k && cur < n - 1)
    {
        cur++;
        char c = s[cur];
        char f = c - k;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] >= f && s[i] <= c)
                s[i] = f;
        }
    }
    cout << s << '\n';
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