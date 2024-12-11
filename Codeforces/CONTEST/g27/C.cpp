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

void solve()
{
    ll n;
    cin >> n;
    if (n == 5)
    {
        cout << "5\n2 1 3 4 5\n";
        return;
    }

    auto ispwr2 = [&](ll n) -> bool
    {
        return (n & (n - 1)) == 0;
    };
    auto last = [&](ll n) -> ll
    {
        ll ans = 1;
        while (ans <= n)
            ans <<= 1;
        return ans - 1;
    };
    auto prev = [&](ll n) -> ll
    {
        ll ans = 1;
        while (ans < n)
            ans <<= 1;

        ans >>= 1;
        return ans - 1;
    };

    auto evenc1 = [&](ll n) -> void
    {
        ll pr1 = prev(n);
        // cout << "prev" << pr1 << '\n';
        for (ll i = 1; i <= n - 2; i++)
        {
            if (i != pr1)
                cout << i << " ";
        }
        cout << n - 1 << " " << n << " " << pr1 << " ";
        return;
    };
    auto oddc1 = [&](ll n) -> void
    {
        evenc1(n - 1);
        cout << n << " ";
        return;
    };

    auto evenc2 = [&](ll n) -> void
    {
        oddc1(n - 1);
        cout << n << " ";
    };
    auto oddc2 = [&](ll n) -> void
    {
        evenc2(n - 1);
        cout << n << " ";
    };

    if (ispwr2(n))
    {
        cout << last(n) << '\n';
        evenc2(n);
        cout << '\n';
    }
    else if (n % 2 == 0)
    {
        cout << last(n) << '\n';
        evenc1(n);
        cout << '\n';
    }
    else if (n % 2 == 1)
    {
        if (ispwr2(n - 1))
        {
            cout << n << '\n';
            oddc2(n);
            cout << '\n';
        }
        else
        {
            cout << n << '\n';
            oddc1(n);
            cout << '\n';
        }
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