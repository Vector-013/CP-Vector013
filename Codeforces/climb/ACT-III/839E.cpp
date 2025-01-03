#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 2e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a != i)
            cnt1++;
        if (a != n - i + 1)
            cnt2++;
        if (a != i && a != n - i + 1)
            cnt3++;
    }
    if (cnt1 + cnt3 <= cnt2)
    {
        cout << "First\n";
        return;
    }
    if (cnt2 + cnt3 < cnt1)
    {
        cout << "Second\n";
        return;
    }
    cout << "Tie\n";
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