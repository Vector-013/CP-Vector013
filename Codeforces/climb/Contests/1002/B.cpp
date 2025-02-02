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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    if (k == n)
    {
        vector<int> b;
        for (int i = 1; i < n; i += 2)
            b.push_back(a[i]);
        b.push_back(0);
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] != i + 1)
            {
                cout << i + 1 << '\n';
                return;
            }
        }
        cout << k / 2 + 1 << '\n';
        return;
    }
    for (int i = 1; i < n - k + 2; i++)
    {
        if (a[i] == 1)
            continue;
        cout << "1\n";
        return;
    }
    cout << "2\n";
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
