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
    int x = stoi(s);
    vector<pair<int, int>> v;
    if (x == 1)
    {
        cout << 9999 << '\n';
        for (int i = 2; i <= 10000; i++)
        {
            cout << i << " " << i - 1 << '\n';
        }
        return;
    }
    if (n == 1)
    {
        for (int i = 2; i <= 4; i++)
        {
            string q = s;
            for (int j = 1; j < i; j++)
                q += s;
            int z = stoi(q);
            int p = z - i;
            if (!(p % (x - 1)) && (p / (x - 1) > 0))
            {
                int a = p / (x - 1);
                int b = a - i;
                if (a > 0 && b > 0 && a <= 10000 && b <= 10000)
                {
                    v.push_back({a, b});
                }
            }
        }
        cout << v.size() << '\n';
        for (auto p : v)
            cout << p.first << ' ' << p.second << '\n';
    }
    if (n == 2)
    {
        for (int i = 3; i <= 7; i++)
        {
            // q is s then adding first and second character of s till i times
            string q = "";
            for (int j = 1; j <= i / 2; j++)
                q += s;
            if (i % 2)
                q += s[0];

            int z = stoi(q);
            int p = z - i;
            // cout << z << ' ' << p << '\n';
            if (!(p % (x - 2)) && (p / (x - 2) > 0))
            {
                int a = p / (x - 2);
                int b = 2 * a - i;
                if (a > 0 && b > 0 && a <= 10000 && b <= 10000)
                {
                    v.push_back({a, b});
                }
            }
        }
        cout << v.size() << '\n';
        for (auto p : v)
            cout << p.first << ' ' << p.second << '\n';
    }
    if (n == 3)
    {
        cout << 0 << '\n';
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