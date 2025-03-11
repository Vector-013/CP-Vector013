#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 998244353;

void solve()
{
    stack<int> s;
    for (int i = 0; i < 100; i++)
        s.push(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b;
            cin >> b;
            s.push(b);
        }
        else
        {
            int x = s.top();
            s.pop();
            cout << x << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}