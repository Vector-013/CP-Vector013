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
    vector<ld> v(n);
    for (ld &i : v)
        cin >> i;
    if (v[0] > v[1])
        reverse(v.begin(), v.end());
    if (n == 2)
    {
        cout << "Yes\n";
        return;
    }
    ld r = v[1] / v[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] * r != v[i + 1])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    solve();
}