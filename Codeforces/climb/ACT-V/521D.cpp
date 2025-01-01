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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int l = 1, r = n;
    auto can = [&](int am)
    {
        int C = 0;
        for (auto i : cnt)
        {
            C += i.second / am;
        }
        return C >= k;
    };
    while (l < r)
    {
        int mid = l + r + 1;
        mid /= 2;
        if (can(mid))
            l = mid;
        else
            r = mid - 1;
    }
    vector<int> ans;
    for (auto i : cnt)
    {
        for (int j = 0; j < i.second / l; j++)
        {
            if (ans.size() < k)
                ans.push_back(i.first);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i)
            cout << " ";
        cout << ans[i];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
}