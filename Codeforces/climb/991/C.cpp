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
    string s;
    cin >> s;
    int n = s.size();
    ll sumd = 0;
    ll c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++)
    {
        sumd += (s[i] - '0');
        if ((s[i] == '2'))
            c2++;
        if ((s[i] == '3'))
            c3++;
    }
    int rem = sumd % 9;
    if (rem == 0)
    {
        cout << "YES\n";
        return;
    }
    vector<bool> mod92(9, false);
    vector<bool> mod96(9, false);
    ll s1 = 0;
    for (int i = 0; i <= c2; i++)
    {
        s1 = 2 * i;
        mod92[s1 % 9] = true;
    }
    for (int i = 0; i <= c3; i++)
    {
        s1 = 6 * i;
        mod96[s1 % 9] = true;
    }
    for (int i = 0; i < 9; i++)
    {
        if (mod92[i])
        {
            for (int j = 0; j < 9; j++)
            {
                if (mod96[j] && (i + j + rem) % 9 == 0)
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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