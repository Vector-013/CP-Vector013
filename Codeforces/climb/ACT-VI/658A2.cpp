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
    string s, w;
    cin >> s >> w;
    vector<int> a, b;
    int ch = 0;
    int ch2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] - '0' == ch)
        {
            a.push_back(i + 1);
            ch ^= 1;
        }
        if (w[i] - '0' == ch2)
        {
            b.push_back(i + 1);
            ch2 ^= 1;
        }
    }
    cout << a.size() + b.size() << '\n';
    reverse(a.begin(), a.end());
    for (auto &x : a)
        cout << x << " ";
    for (auto &x : b)
        cout << x << " ";
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