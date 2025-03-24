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
    vector<array<int, 3>> a(n);
    for (auto &x : a)
        cin >> x[1];

    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (not s.empty() and a[s.top()][1] >= a[i][1])
            s.pop();
        a[i][2] = s.empty() ? n : s.top();
        s.push(i);
    }
    s = stack<int>();
    for (int i = 0; i < n; i++)
    {
        while (not s.empty() and a[s.top()][1] >= a[i][1])
            s.pop();
        a[i][0] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    sort(a.begin(), a.end(), [](auto &x, auto &y)
         {
        if(x[1]==y[1])return x[2]-x[0]>y[2]-y[0];
        return x[1]>y[1]; });
    vector<int> ans(n);
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = (a[i][2] - a[i][0] - 1);
        while (k < x)
            ans[k++] = a[i][1];
    }

    for (auto &x : ans)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}