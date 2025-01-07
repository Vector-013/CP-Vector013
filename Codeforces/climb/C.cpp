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
    int l, r;
    cin >> l >> r;
    int i = 0;
    string s = bitset<32>(l).to_string();
    string t = bitset<32>(r).to_string();
    while (s[i] == t[i])
        i++;
    string a = t.substr(0, i);
    string b = a;
    a += "1";
    b += "0";
    a += string(32 - a.size(), '0');
    b += string(32 - b.size(), '1');
    int x1 = bitset<32>(a).to_ulong();
    int x2 = bitset<32>(b).to_ulong();
    cout << x1 << " " << x2 << " ";
    if (x1 + 1 <= r)
        cout << x1 + 1 << '\n';
    else
        cout << x2 - 1 << '\n';
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