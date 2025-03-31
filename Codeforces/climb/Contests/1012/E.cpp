#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;
const int mod = 1e9 + 7;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n), b(2 * n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        a[i] = a[i + n] = a[i] - b[i];
    }
    for (int i = 1; i < 2 * n; ++i)
        a[i] += a[i - 1];
    int ans = -1, j = 0;
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() and a[st.top()] > a[i])
            st.pop();
        if (i < n)
            ans = max(ans, st.top() - i);
        st.push(i);
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}