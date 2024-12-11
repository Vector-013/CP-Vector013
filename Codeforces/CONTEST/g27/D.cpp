#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <string>
#include <numeric>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    ll q;

    auto num2 = [](ll n) -> ll
    {
        ll cnt = 0;
        while (n % 2 == 0)
        {
            n /= 2;
            cnt++;
        }
        return cnt;
    };
    ll curmaxi = 0;
    ll sum = 0;
    ll far2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        far2 += num2(q);
        
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