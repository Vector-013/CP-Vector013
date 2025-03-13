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
    int n, x, rd;
    cin >> n;
    int a = 1, b = 2, c = 3;
    while (1)
    {
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        cout.flush();
        cin >> x;
        if (x == 0)
            break;
        rd = rand() % 3;
        if (rd == 0)
            a = x;
        if (rd == 1)
            b = x;
        if (rd == 2)
            c = x;
    }
    cout << "! " << a << ' ' << b << ' ' << c << '\n';
    cout.flush();
}

int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}