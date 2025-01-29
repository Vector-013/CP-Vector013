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
    vector<int> v(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
    }
    auto z = v;
    auto t = v;
    sort(z.begin(), z.end());
    for (int i = 1; i < 5; i++)
    {
        swap(v[i], v[i - 1]);
        if (v == z)
        {
            cout << "Yes\n";
            return;
        }
        v = t;
    }
    cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}