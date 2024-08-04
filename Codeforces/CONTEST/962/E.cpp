#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

void solve()
{
    string S;
    cin >> S;

    int n = S.size();
    S = " " + S;

    vector<int> P(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        P[i] = (S[i] == '1' ? 1 : -1) + P[i - 1];
    }

    map<int, ll> cnt;
    ll ans = 0;

    for (int i = 0; i <= n; i++)
    {
        ans = (ans + (n - i + 1) * cnt[P[i]]) % MOD;
        cnt[P[i]] = (cnt[P[i]] + (i + 1)) % MOD;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}