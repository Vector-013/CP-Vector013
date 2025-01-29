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
    ll n, d;
    cin >> n >> d;
    vector<int> v, w;
    v.push_back(1);
    for (int i = 3; i < 10; i += 2)
    {
        if (d % i == 0)
            v.push_back(i);
        else
            w.push_back(i);
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