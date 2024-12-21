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
    string s1, s2;
    cin >> s1 >> s2;
    bool finis = false;
    bool unique = true;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '#' && s2[i] == '#')
        {
            continue;
        }
        else if (s1[i] == '.' && s2[i] == '.')
        {
            if (i < n - 1 && s1[i + 1] == '.' && s2[i + 1] == '.')
            {
                unique = false;
                s1[i] = s1[i + 1] = s2[i] = s2[i + 1] = '#';
                continue;
            }
            s1[i] = s2[i] = '#';
        }
        else if (s1[i] == '.')
        {
            if (i < n && s1[i + 1] == '.')
            {
                s1[i] = s1[i + 1] = '#';
                continue;
            }
            else
            {
                cout << "None\n";
                return;
            }
        }
        else
        {
            if (i < n && s2[i + 1] == '.')
            {
                s2[i] = s2[i + 1] = '#';
                continue;
            }
            else
            {
                cout << "None\n";
                return;
            }
        }
    }
    cout << (unique ? "Unique\n" : "Multiple\n");
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