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
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i * (2 * i - 1);
    cout << sum << " " << 2 * n << '\n';
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 1);
    for (int i = n; i >= 1; i--)
    {
        cout << 1 << " " << i << " ";
        for (auto x : seq)
            cout << x << " ";
        cout << '\n';
        cout << 2 << " " << i << " ";
        for (auto x : seq)
            cout << x << " ";
        cout << '\n';
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