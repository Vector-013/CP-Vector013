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
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    while (s.back() == '0')
        s.pop_back();
    n = s.size();
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        v[i] = s[i] - '0';
    for (int i = n - 2; i >= 0; i--)
        v[i] += v[i + 1];
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 10)
        {
            if (i == n - 1)
            {
                v.push_back(0);
                n++;
            }
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        cout << v[i];
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