#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    set<int> s(x.begin(), x.end());
    if (s.size() < n)
    {
        int q;
        for (int i = 1; i <= n; i++)
        {
            if (s.find(i) == s.end())
            {
                q = i;
                break;
            }
        }
        cout << "? " << q << " " << 1 + (q == 1) << endl;
        cout.flush();
        int ans;
        cin >> ans;
        cout << "! " << (ans ? "B" : "A") << endl;
        cout.flush();
    }
    else
    {
        int a, b;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == 1)
                a = i + 1;
            if (x[i] == n)
                b = i + 1;
        }
        cout << "? " << a << " " << b << endl;
        cout.flush();
        int ans;
        cin >> ans;
        if (ans < n - 1)
        {
            cout << "! A" << endl;
        }
        else if (ans > n - 1)
        {
            cout << "! B" << endl;
        }
        else
        {
            cout << "? " << b << ' ' << a << endl;
            cin >> ans;
            if (ans == n - 1)
            {
                cout << "! B" << endl;
            }
            else
            {
                cout << "! A" << endl;
            }
        }
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
