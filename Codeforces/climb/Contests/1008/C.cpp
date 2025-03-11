#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    int n;
    cin >> n;
    vector<ll> b(2 * n);
    for (auto &x : b)
        cin >> x;
    sort(b.begin(), b.end());

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i)
        x[i] = b[i];
    for (int i = n; i < 2 * n; ++i)
        y[i - n] = b[i];

    ll ss = accumulate(y.begin(), y.end(), 0LL) - accumulate(x.begin(), x.end(), 0LL);
    bool there = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (b[i] == ss)
        {
            there = 1;
            break;
        }
    }
    if (!there)
    {
        cout << ss << " ";
        for (int i = 0; i < n; ++i)
        {
            cout << y[i] << " " << x[i] << " \n"[i == n - 1];
        }
        return;
    }
    ll a1 = *max_element(b.begin(), b.end());
    b.erase(find(b.begin(), b.end(), a1));
    sort(b.begin(), b.end());
    x.clear();
    y.clear();
    x.resize(n - 1);
    y.resize(n);
    for (int i = 0; i < n - 1; ++i)
        x[i] = b[i];
    for (int i = n - 1; i < 2 * n - 1; ++i)
        y[i - n + 1] = b[i];
    ss = accumulate(x.begin(), x.end(), 0LL) - accumulate(y.begin(), y.end(), 0LL);
    ll z = a1 - ss;
    x.push_back(z);

    cout << a1 << " ";
    for (int i = 0; i < n; ++i)
    {
        cout << x[i] << " " << y[i] << " \n"[i == n - 1];
    }
    return;
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