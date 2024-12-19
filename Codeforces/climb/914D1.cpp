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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    vector<pair<ll, ll>> vp;
    vector<int> right(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i] > b[i])
            flag = false;
        if (a[i] < b[i])
            vp.push_back({b[i], i});
        if (a[i] == b[i])
            right[i] = 1;
    }
    if (flag == false)
    {
        cout << "NO\n";
        return;
    }
    sort(vp.begin(), vp.end());
    for (auto pr : vp)
    {
        int val = pr.first;
        int idx = pr.second;
        int r = n;
        for (int i = idx + 1; i < n; i++)
        {
            if (a[i] == val)
            {
                r = i;
                break;
            }
            if (right[i] || a[i] > val)
            {
                break;
            }
        }
        int l = n;
        for (int i = idx - 1; i >= 0; i--)
        {
            if (a[i] == val)
            {
                l = i;
                break;
            }
            if (right[i] || a[i] > val)
            {
                break;
            }
        }
        if (l == n && r == n)
        {
            cout << "NO\n";
            return;
        }
        else
        {
            right[idx] = 1;
            a[idx] = val;
        }
    }
    cout << (a == b ? "YES" : "NO") << '\n';
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