#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef unsigned long long ull;
typedef long double ld;
const int inf = 2e9;
const ll linf = 9e18;

void solve()
{
    string s;
    cin >> s;
    string ans = s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int next = i;
        int num = s[i] - '0';
        for (int j = 1; j < 10 && i + j < n; j++)
        {
            if (((s[i + j] - '0') - j) > num)
            {
                next = i + j;
                num = (s[i + j] - '0') - j;
            }
        }
        // cout << "i = " << i << " next = " << next << " num = " << num << '\n';
        for (int k = next; k > i; k--)
        {
            swap(s[k], s[k - 1]);
        }
        ans[i] = ('0' + num);
    }
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