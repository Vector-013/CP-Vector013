#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

string solve(string s)
{
    int n = s.length();
    if (n == 0)
        return s;

    int left = 0;
    for (int right = n - 1; right >= 0; right--)
    {
        if (s[right] == s[left])
        {
            left++;
        }
    }

    if (left == n)
        return s;

    string z = s.substr(left);
    string v =
        string(z.rbegin(), z.rend());

    return v + solve(s.substr(0, left)) + z;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    string need = solve(s);
    reverse(need.begin(), need.end());
    cout << need << '\n';
}
