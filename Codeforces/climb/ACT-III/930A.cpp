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
    int maxi = 0;
    auto query = [&](int a, int b, int c, int d) -> char
    {
        cout << "? " << a << " " << b << " " << c << " " << d << endl;
        cout.flush();
        char x;
        cin >> x;
        return x;
    };
    for (int i = 1; i < n; i++)
    {
        char m = query(maxi, maxi, i, i);
        if (m == '<')
            maxi = i;
    }
    vector<int> mx;
    mx.push_back(0);
    int cur = 0;
    for (int i = 1; i < n; i++)
    {
        char m = query(maxi, cur, maxi, i);
        if (m == '=')
            mx.push_back(i);
        else if (m == '<')
        {
            mx.clear();
            mx.push_back(i);
            cur = i;
        }
    }
    int second = mx[0];
    for (int i = 1; i < mx.size(); i++)
    {
        char m = query(second, second, mx[i], mx[i]);
        if (m == '>')
            second = mx[i];
    }
    cout << "! " << maxi << " " << second << endl;
    cout.flush();
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