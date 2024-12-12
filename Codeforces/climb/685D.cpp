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
    ll d, k;
    cin >> d >> k;
    ll x = 0ll;
    while ((x + k) * (x + k) * 2 <= d * d)
        x += k;

    if ((x + k) * (x + k) + x * x <= d * d)
        cout << "Ashish\n";
    else
        cout << "Utkarsh\n";
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