#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    vector<int> v(7);
    map<int, int> mp;
    int b2 = 0, b3 = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto x : mp)
    {
        if (x.second >= 3)
            b3++;
        else if (x.second == 2)
            b2++;
    }

    cout << ((b3 >= 2 or (b3 >= 1 and b2 >= 1)) ? "Yes\n" : "No\n");
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}