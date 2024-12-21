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
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int mul = 0;
    i64 ans = 0;
    for (int i = 1; i < n; i++)
    {
        int x = 0;
        while ((a[i] << x) < a[i - 1])
        {
            x++;
        }
        while (x <= 0 && (a[i] >> (-x + 1)) >= a[i - 1])
        {
            x--;
        }
        int res = std::max(0, x + mul);
        mul = res;
        ans += res;
    }
    std::cout << ans << "\n";
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