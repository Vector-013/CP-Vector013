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
    ll n, k;
    cin >> n >> k;
    if (k == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    string s = bitset<64>(k - 1).to_string();
    s = s.substr(s.find('1'));
    // cout << s << '\n';
    if (s.size() >= n)
    {
        cout << "-1\n";
        return;
    }
    vector<int> a(n, -1);

    s = string(n - s.size() - 1, '0') + s;
    int z = s.size();
    int f = 0, e = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '0')
        {
            a[f] = i + 1;
            f++;
        }
        else
        {
            a[e] = i + 1;
            e--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            cout << n << ' ';
            continue;
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
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