#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 998244353;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] == s[j])
            s[i] = s[j] = '0';
        else
            break;
        i++, j--;
    }
    string x = "";
    for (int i = 0; i < n; ++i)
        if (s[i] != '0')
            x += s[i];
    n = x.size();
    if (n == 0)
    {
        cout << "0\n";
        return;
    }
    assert(x[0] != x[n - 1]);
    auto play = [&](string w) -> int
    {
        assert(!w.empty());
        int i = w.size() / 2;
        while (i >= 1 && w[i - 1] == w[w.size() - i])
            i--;

        int cnt[26] = {};
        for (int j = 0; j < i; j++)
        {
            cnt[w[j] - 'a']++;
            cnt[w[w.size() - j - 1] - 'a']--;
        }
        bool ok = true;
        for (int j = 0; j < 26; j++)
            if (cnt[j] != 0)
                ok = false;
        if (ok)
            return i;
        int R[26] = {},
            L[26] = {};
        for (auto c : w)
            R[c - 'a']++;
        for (int i = 1; i <= w.size(); i++)
        {
            L[w[i - 1] - 'a']++;
            R[w[i - 1] - 'a']--;
            bool ok = true;
            for (int j = 0; j < 26; j++)
                if (L[j] < R[j])
                    ok = false;
            if (ok)
                return i;
        }
        assert(false);
    };

    int ans = play(x);
    reverse(x.begin(), x.end());
    ans = min(ans, play(x));
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
