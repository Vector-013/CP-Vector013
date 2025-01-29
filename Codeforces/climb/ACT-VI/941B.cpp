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
    int z = __builtin_clz(k);
    int first = 31 - z;
    cout << "first: " << first << '\n';
    int num = 1 << first;
    cout << "num: " << num << '\n';
    int ans = 1;
    cout << "25\n";
    int cnt = 0;
    for (int i = 0; i < 23; i++)
    {
        if (ans == num)
        {
            ans = ans << 1;
            continue;
        }
        cout << ans << " ";
        ans = ans << 1;
    }
    cout << k + 1 << " " << k - num << " " << k + num + 1 << '\n';
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