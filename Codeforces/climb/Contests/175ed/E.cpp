#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    ll ans = n * (n + 1ll) / 2;

    int x = n + 1;
    vector<int> k(4 * n + 100);
    k[x] = 1;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            cnt += k[x + 2] + k[x + 3] + k[x + 4];
            x += 3;
        }
        else
        {
            cnt -= k[x + 1];
            x--;
        }
        ans -= cnt - k[x - 1];
        k[x]++;
        cnt++;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}