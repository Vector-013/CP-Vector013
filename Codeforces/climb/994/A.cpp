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
    vector<int> a(n);
    int nonz = 0;
    int loc1 = -1, loc2 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
        {
            nonz++;
            if (loc1 == -1)
                loc1 = i;
            else
                loc2 = i;
        }
    }
    if (!nonz)
    {
        cout << "0\n";
        return;
    }
    for (int i = loc1; i < loc2; i++)
    {
        if (a[i] == 0)
        {
            cout << "2\n";
            return;
        }
    }
    cout << "1\n";
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