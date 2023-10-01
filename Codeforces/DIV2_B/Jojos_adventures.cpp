#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
const int INF = 2e9;
typedef long long ll;
typedef long double ld;
void solve()
{
    string s;
    cin >> s;
    ll cnt = 0;
    ll l = s.length();
    double maxi = 0;
    for (int i = 0; i < l * 2; i++)
    {
        if (s[i % l] == '1')
            cnt++;
        maxi = max((double)cnt, maxi);
        if (s[i % l] == '0')
            cnt = 0;
    }
    maxi = max(maxi, (double)cnt);
    if (maxi == l * 2)
    {
        cout << l * l << '\n';
        return;
    }
    ll ans = ceil((maxi + 1) / 2) * floor((maxi + 1) / 2);
    cout << ans << '\n';
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