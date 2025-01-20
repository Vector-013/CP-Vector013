#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int cnt = 0;
    vector<int> v = a;
    int mini, pos = -1;
    int i = 1;
    while (i < n)
    {
        mini = min(a[i], a[i - 1]);
        a[i] -= mini;
        a[i - 1] -= mini;
        cnt = (a[i - 1] > a[i]);
        if (cnt)
            break;
        i++;
    }
    if (!cnt)
    {
        cout << "YES\n";
        return;
    }
    cnt = 0;
    i = 0;
    while (i < n - 1)
    {
        if (v[i - 1] <= v[i])
        {
            i++;
            continue;
        }
        pos = i;
        i++;
    }
    int j = pos;
    while (j >= 1)
    {
        mini = min(v[j], v[j - 1]);
        v[j] -= mini;
        v[j - 1] -= mini;
        j--;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cnt = (v[i] > v[i + 1]);
        if (cnt)
            break;
    }

    cout << (cnt ? "NO\n" : "YES\n");
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}