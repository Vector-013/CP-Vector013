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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> q(n);
    map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    set<int> ss;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        q[i] = {v[i] >> 2, i};
        ss.insert(v[i] >> 2);
        mp[v[i] >> 2].push(v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << mp[v[i] >> 2].top() << ' ';
        mp[v[i] >> 2].pop();
    }
    cout << '\n';
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