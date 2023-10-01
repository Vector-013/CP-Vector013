#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
void solve()
{
    int n, k, ans = 0, con = 0, max = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[27] = {}, A[27] = {};
    for (int i = 0; i < n; i++)
    {
        if (s[i] > 91)
            a[s[i] - 96]++;
        else
            A[s[i] - 64]++;
    }
    for (int i = 1; i < 27; i++)
    {
        con = con + min(a[i], A[i]);
        max += (a[i] + A[i]) / 2;
    }
    ans = min(con + k, max);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
