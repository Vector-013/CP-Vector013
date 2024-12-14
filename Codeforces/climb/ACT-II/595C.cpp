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
    ll n;
    cin >> n;

    auto ternary = [](ll n)
    {
        string s = "";
        while (n)
        {
            s += to_string(n % 3);
            n /= 3;
        }
        reverse(s.begin(), s.end());
        return s;
    };
    auto str2num = [](string s)
    {
        ll num = 0;
        ll base = 1;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++)
        {
            num += (s[i] - '0') * base;
            base *= 3;
        }
        return num;
    };
    string s = ternary(n);
    int z = s.length();
    // cout << s << '\n';
    int pos2 = s.find('2');
    if (pos2 != -1)
    {
        int zpos = -1;
        for (int i = pos2 - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                zpos = i;
                break;
            }
        }
        if (zpos != -1 && zpos < pos2)
        {
            s[zpos] = '1';
            for (int i = zpos+1; i < s.length(); i++)
                s[i] = '0';
        }
        else
        {
            s = "1" + string(z, '0');
        }
    }
    // cout << ternary(8748) << '\n';
    // cout << s << '\n';
    cout << str2num(s) << '\n';
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