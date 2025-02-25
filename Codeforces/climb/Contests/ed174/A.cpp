#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
int solve(string S)
{
    assert(!S.empty());
    {
        int i = S.size() / 2;
        while (i >= 1 && S[i - 1] == S[S.size() - i])
            i--;
        assert(i >= 1);
        int cnt[26] = {};
        for (int j = 0; j < i; j++)
        {
            cnt[S[j] - 'a']++;
            cnt[S[S.size() - j - 1] - 'a']--;
        }
        bool ok = true;
        for (int j = 0; j < 26; j++)
            if (cnt[j] != 0)
                ok = false;
        if (ok)
            return i;
    }
    int R[26] = {}, L[26] = {};
    for (char c : S)
        R[c - 'a']++;
    for (int i = 1; i <= S.size(); i++)
    {
        L[S[i - 1] - 'a']++;
        R[S[i - 1] - 'a']--;
        bool ok = true;
        for (int j = 0; j < 26; j++)
            if (L[j] < R[j])
                ok = false;
        if (ok)
            return i;
    }
    assert(false);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;)
    {
        string S;
        cin >> S;
        int k = 0;
        while (k < S.size() && S[k] == S[S.size() - 1 - k])
            k++;
        if (k == S.size())
        {
            cout << "0\n";
            continue;
        }
        assert(k < (int)S.size() - 1 - k);
        S = S.substr(k, S.size() - k - k);
        assert(S[0] != S[S.size() - 1]);
        int ans = solve(S);
        reverse(S.begin(), S.end());
        ans = min(ans, solve(S));
        cout << ans << "\n";
    }
}
