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
    int n, a, c, d;
    cin >> n >> c >> d;
    vector<int> v(n);
    vector<int> w, z(n * n);
    for (int i = 0; i < n * n; i++)
        cin >> z[i];
    sort(z.begin(), z.end());
    v[0] = z[0];
    for (int i = 1; i < n; i++)
        v[i] = v[i - 1] + c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            w.push_back(v[i] + j * d);
    sort(w.begin(), w.end());
    cout << (w == z ? "Yes" : "No") << '\n';
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