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
    int n, k;
    cin >> n >> k;
    vector<int> a(n, -1);
    bool inc = 1;
    int left = n;
    int s = 1, e = n;
    while (left)
    {
        for (int i = 0; i < k; i++)
        {
            if (inc)
            {
                for (int j = i; j < n; j += k)
                {
                    a[j] = s++;
                    left--;
                }
            }
            else
            {
                for (int j = i; j < n; j += k)
                {
                    a[j] = e--;
                    left--;
                }
            }
            inc = !inc;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
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