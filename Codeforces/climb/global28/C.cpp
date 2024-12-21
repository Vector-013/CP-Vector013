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
    string s;
    cin >> s;
    int n = s.size();
    if (find(s.begin(), s.end(), '0') == s.end())
    {
        cout << 1 << " " << n << " " << 1 << " " << 1 << '\n';
        return;
    }
    int pos = find(s.begin(), s.end(), '0') - s.begin();
    int l = n - pos;
    int l1, r1, l2, r2;
    auto xors = [&](string a, string b) -> string
    {
        if (a.size() < b.size())
            a.insert(0, b.size() - a.size(), '0');
        else if (b.size() < a.size())
            b.insert(0, a.size() - b.size(), '0');

        string res;
        for (int i = 0; i < a.size(); i++)
            res += (a[i] == b[i] ? '0' : '1');
        return res;
    };

    string w = s.substr(0, l);
    string x = xors(w, s);
    // cout << "x: " << x << "\n\n";
    l1 = 1, r1 = n, l2 = 1, r2 = l;

    for (int i = 1; i < pos; i++)
    {

        string w = s.substr(i, l);
        string tmp = xors(w, s);
        // cout << "tmp: " << tmp << '\n';

        if (x < tmp)
        {
            x = tmp;
            l2 = i + 1;
            r2 = i + l;
        }
        // cout << "x: " << x << '\n';
    }
    cout << l1 << " " << r1 << " " << l2 << " " << r2 << '\n';
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