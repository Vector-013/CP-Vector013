#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll sz = 1e6 + 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll odp[sz], cdp[sz];
    odp[1] = 1ll, cdp[1] = 1ll;
    for (ll i = 2; i < sz; i++)
    {
        odp[i] = ((2ll * odp[i - 1]) % mod + cdp[i - 1] % mod) % mod;
        cdp[i] = (odp[i - 1] % mod + (4ll * cdp[i - 1]) % mod) % mod;
    }
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (odp[n] + cdp[n]) % mod << '\n';
    }
}