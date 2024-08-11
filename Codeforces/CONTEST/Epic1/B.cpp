#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, cnt = 0, totalgap = 0, maxgap = 0;
    cin >> n;
    vector<long long> v(n), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    a[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] >= a[i - 1])
        {
            a[i] = v[i];
        }
        else
        {
            a[i] = a[i - 1];
            maxgap = max(maxgap, a[i] - v[i]);
            totalgap += a[i] - v[i];
        }
    }
    cout << totalgap + maxgap << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}